/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 11:19:26 by scaussin          #+#    #+#             */
/*   Updated: 2014/05/18 11:34:06 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_42sh.h"
#include "libft.h"

void	ft_setenv(char ***env, char **arg)
{
	int		i;

	i = 0;
	while (arg && arg[i])
		i++;
	if (arg && arg[1] && ft_strchr(arg[1], '='))
	{
		ft_putendl_fd("Usage: setenv [NAME] [VALUE]", 2);
		return ;
	}
	if (i > 1)
	{
		i = 0;
		ft_find_env((*env), &i, arg[1]);
		ft_set(env, arg, i);
	}
	else
		ft_env(env, NULL);
}

void	ft_unsetenv(char ***env, char **arg)
{
	int		j;
	char	*tmp;

	j = 1;
	tmp = NULL;
	if (!arg[j])
		ft_putendl_fd("Usage: unsetenv [VAR_ENV_NAME ...]", 2);
	while (arg[j])
	{
		tmp = ft_strjoin(arg[j], "=");
		ft_unset(env, tmp);
		ft_strdel(&tmp);
		j++;
	}
}

void	ft_unset(char ***env, char *tmp)
{
	int		i;

	i = 0;
	while ((*env)[i] && ft_strncmp((*env)[i], tmp, ft_strlen(tmp)))
		i++;
	if ((*env)[i])
	{
		ft_strdel(&(*env)[i]);
		while ((*env)[i + 1])
		{
			(*env)[i] = (*env)[i + 1];
			i++;
		}
		(*env)[i] = NULL;
	}
	else
		ft_putendl_fd("Error: variable does not exist", 2);
}

int		ft_builtin(char ***env, char **arg)
{
	int		i;
	t_ptr	*ptr_f;

	i = 0;
	ptr_f = NULL;
	ft_ptr_fct(&ptr_f);
	while (arg && i < 6)
	{
		if (arg[0])
		{
			if (ft_strcmp(ptr_f[i].s, arg[0]) == 0)
			{
				ptr_f[i].fct(env, arg);
				free_ptr(&ptr_f);
				return (1);
			}
			i++;
		}
	}
	free_ptr(&ptr_f);
	return (0);
}

void	free_ptr(t_ptr **ptr_f)
{
	int		i;

	i = 0;
	while ((*ptr_f)[i].s)
	{
		ft_strdel(&((*ptr_f)[i].s));
		i++;
	}
	free((*ptr_f));
}
