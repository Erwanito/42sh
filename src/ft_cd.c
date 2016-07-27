/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 19:04:07 by scaussin          #+#    #+#             */
/*   Updated: 2014/05/18 14:07:28 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"

void	ft_dash(char ***env)
{
	char	*pwd;
	char	*old;

	if (get_var(env, "PWD", &pwd))
		return ;
	if (get_var(env, "OLDPWD", &old))
		return ;
	ft_strdel(&pwd);
	pwd = ft_cpy_cnt(env, "PWD=");
	ft_strdel(&old);
	old = ft_cpy_cnt(env, "OLDPWD=");
	if (chdir(old))
		ft_errno();
	else
	{
		ft_mk_arg(env, "OLDPWD", pwd);
		ft_mk_arg(env, "PWD", old);
	}
	ft_strdel(&pwd);
	ft_strdel(&old);
}

int		get_var(char ***env, char *var, char **tmp)
{
	int		i;

	i = 0;
	ft_find_env((*env), &i, var);
	if ((*env)[i])
	{
		(*tmp) = ft_strdup((*env)[i]);
		return (0);
	}
	else
	{
		ft_printf("Variable %s not set\n", var);
		return (i);
	}
}

void	ft_mk_arg(char ***env, char *arg1, char *arg2)
{
	char	**tmp;

	if ((tmp = (char **)malloc(sizeof(char *) * 4)) == NULL)
		ft_error("Malloc tmp ft_dash fail");
	tmp[0] = ft_strdup("setenv");
	tmp[1] = ft_strdup(arg1);
	tmp[2] = ft_strdup(arg2);
	tmp[3] = NULL;
	ft_setenv(env, tmp);
	ft_strdel2d(&tmp);
}

char	*cd_tild(char ***env, char **arg, int t[3], char *tmp)
{
	char	*tmp2;

	t[2] = 0;
	if (arg[t[0]])
	{
		t[2] = 1;
		tmp = arg[t[0]];
		arg[t[0]] = ft_max_strdup(ft_max_strchr(arg[t[0]], '/'));
		ft_strdel(&tmp);
	}
	tmp = ft_cpy_cnt(env, "HOME=");
	tmp2 = ft_strjoin(tmp, arg[t[0]]);
	ft_strdel(&tmp);
	return (tmp2);
}

char	*get_pwd(char *s1, char *s2)
{
	char	*tmp2;
	char	**tmp2d;
	char	*cpy;

	if (s2 && s2[0] == '/')
		return (s2);
	tmp2d = ft_strsplit(s2, '/');
	tmp2 = ft_strdup(s1);
	pwd_modif(tmp2d, &tmp2);
	ft_strdel2d(&tmp2d);
	ft_strdel(&s2);
	cpy = ft_strdup(tmp2);
	ft_strdel(&tmp2);
	return (cpy);
}
