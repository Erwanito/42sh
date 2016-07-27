/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 11:17:14 by scaussin          #+#    #+#             */
/*   Updated: 2014/03/27 22:05:29 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include "libft.h"
#include <stdlib.h>

void	get_env(char **env, char ***cpy, int bool)
{
	int		i;

	i = 0;
	if (bool)
	{
		ft_find_env(env, &i, "PATH");
		if (((*cpy) = (char **)malloc(sizeof(char *) * 2)) == NULL)
			ft_error("Malloc envtmp_ifi fail");
		(*cpy)[0] = ft_strdup(env[i]);
		(*cpy)[1] = NULL;
	}
	else
	{
		while (env[i])
			i++;
		if (((*cpy) = (char **)malloc(sizeof(char *) * (i + 1))) == NULL)
			ft_error("Realloc setenv fail");
		i = 0;
		while (env[i])
		{
			(*cpy)[i] = ft_strdup(env[i]);
			i++;
		}
		(*cpy)[i] = NULL;
	}
}

void	ft_ptr_fct(t_ptr **ptr_f)
{
	if ((*ptr_f = (t_ptr *)malloc(sizeof(t_ptr) * 7)) == NULL)
		ft_error("Malloc init ptr_f fail");
	(*ptr_f)[0].s = ft_strdup("cd");
	(*ptr_f)[0].fct = ft_cd;
	(*ptr_f)[1].s = ft_strdup("echo");
	(*ptr_f)[1].fct = ft_echo;
	(*ptr_f)[2].s = ft_strdup("exit");
	(*ptr_f)[2].fct = ft_exit;
	(*ptr_f)[3].s = ft_strdup("env");
	(*ptr_f)[3].fct = ft_env;
	(*ptr_f)[4].s = ft_strdup("setenv");
	(*ptr_f)[4].fct = ft_setenv;
	(*ptr_f)[5].s = ft_strdup("unsetenv");
	(*ptr_f)[5].fct = ft_unsetenv;
	(*ptr_f)[6].s = NULL;
	(*ptr_f)[6].fct = NULL;
}

void	ft_find_env(char **env, int *i, char *arg)
{
	int		n;

	n = ft_strlen(arg);
	if (arg[0] == '\0')
		n = 1;
	while (env[(*i)])
	{
		if (ft_strncmp(env[(*i)], arg, n) == 0)
			break ;
		(*i)++;
	}
}

void	ft_error(char *str)
{
	ft_putendl_fd(str, 2);
}

int		ft_check_section(char *s, char c)
{
	int	i;
	int	section;

	i = 0;
	section = 0;
	if (s == NULL)
		return (0);
	if (s[i] == '\0')
		return (0);
	while (s[i] != c && s[i] != '\0')
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			section++;
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
			i++;
	}
	return (section);
}
