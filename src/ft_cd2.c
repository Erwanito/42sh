/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 18:16:17 by scaussin          #+#    #+#             */
/*   Updated: 2014/03/27 22:26:08 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

void	cd_init(char **tmp, int t[3])
{
	t[0] = 1;
	*tmp = NULL;
	*tmp = getcwd((*tmp), 0);
}

void	cd_trime(char **tmp2)
{
	char	*tmp;

	tmp = get_pwd((*tmp2), NULL);
	ft_strdel(&(*tmp2));
	*tmp2 = ft_strdup(tmp);
	ft_strdel(&tmp);
}

void	cd_secnd(char ***env, char **arg, int t[3], char **tmp2)
{
	if (arg[t[0]] && ft_strncmp(arg[t[0]], "~", 1) == 0)
		*tmp2 = cd_tild(env, arg, t, (*tmp2));
	else
		*tmp2 = ft_strdup(arg[t[0]]);
}

void	cd_prime(char ***env, char *tmp, char *tmp2, int t[3])
{
	ft_mk_arg(env, "OLDPWD", tmp);
	if (t[1] == 1)
	{
		ft_mk_arg(env, "PWD", tmp2);
	}
	else
	{
		ft_strdel(&tmp2);
		tmp2 = getcwd(tmp2, 0);
		ft_mk_arg(env, "PWD", tmp2);
	}
}

void	pwd_modif(char **tmp2d, char **tmp2)
{
	int		i;
	char	*tmp;

	i = -1;
	while (tmp2d && tmp2d[++i])
	{
		if (ft_strcmp(tmp2d[i], "..") == 0)
			ft_bzero(ft_strrchr((*tmp2), '/'),
					ft_strlen(ft_strrchr((*tmp2), '/')));
		else
		{
			tmp = ft_strjoin((*tmp2), "/");
			ft_strdel(&(*tmp2));
			*tmp2 = ft_strjoin(tmp, tmp2d[i]);
			ft_strdel(&tmp);
		}
	}
}
