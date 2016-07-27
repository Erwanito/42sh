/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 11:59:53 by scaussin          #+#    #+#             */
/*   Updated: 2014/05/18 13:26:33 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include "libft.h"
#include <stdlib.h>

void	ft_env(char ***env, char **arg)
{
	int		i;
	char	**envtmp;
	char	*new_arg;

	i = (arg && arg[1] && ft_strcmp(arg[1], "-i") == 0) ? 2 : 1;
	if (arg && arg[1] && ft_strcmp(arg[1], "-i") == 0)
		get_env((*env), &envtmp, 1);
	else
		get_env((*env), &envtmp, 0);
	while (arg && ft_check_section(arg[i], '=') >= 1)
		i++;
	envtmp_add_var(&envtmp, arg, (i - 1));
	if (!arg || !arg[i])
	{
		i = -1;
		while (envtmp[++i])
			ft_putendl(envtmp[i]);
	}
	else
	{
		set_new_arg(arg, &new_arg, i);
		start(new_arg, &envtmp);
	}
	ft_strdel2d(&envtmp);
}

void	set_new_arg(char **arg, char **arg2, int i)
{
	char	*tmp;

	tmp = ft_strdup(arg[i]);
	while (arg[i + 1])
	{
		tmp = ft_splitjoin(tmp, arg[i + 1], ' ');
		i++;
	}
	(*arg2) = ft_strdup(tmp);
	ft_strdel(&tmp);
}

void	envtmp_add_var(char ***env, char **arg, int i)
{
	int		j;
	char	**tmp2;

	if (arg)
		j = (arg[1] && ft_strcmp(arg[1], "-i") == 0) ? 2 : 1;
	while (arg && j <= i)
	{
		tmp2 = ft_strsplit(arg[j], '=');
		if (tmp2[1])
			ft_mk_arg(env, tmp2[0], tmp2[1]);
		else
		{
			if (arg[i][0] == '=')
				ft_mk_arg(env, "\0", tmp2[0]);
			else
				ft_mk_arg(env, tmp2[0], "\0");
		}
		j++;
		ft_strdel2d(&tmp2);
	}
}
