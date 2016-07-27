/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 13:54:56 by scaussin          #+#    #+#             */
/*   Updated: 2014/06/26 11:48:05 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_cd(char ***env, char **arg)
{
	int		t[3];
	char	*tmp;
	char	*tmp2;

	tmp2 = NULL;
	cd_init(&tmp, t);
	if (ft_cd_opt(env, arg, t))
		return (ft_strdel(&tmp));
	if (arg[t[0]])
	{
		cd_secnd(env, arg, t, &tmp2);
		if (t[2])
			cd_trime(&tmp2);
		else
			tmp2 = get_pwd(tmp, tmp2);
	}
	else
		tmp2 = cd_tild(env, arg, t, tmp2);
	if (chdir(tmp2))
		ft_errno();
	else
		cd_prime(env, tmp, tmp2, t);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
}

int		ft_cd_opt(char ***env, char **arg, int t[3])
{
	t[1] = 1;
	t[2] = 0;
	while (arg[t[0]] && arg[t[0]][0] == '-')
	{
		if (arg[t[0]][1] == '\0')
		{
			ft_dash(env);
			return (1);
		}
		if (ft_strncmp(arg[t[0]], "-L", 2) != 0
			&& ft_strncmp(arg[t[0]], "-P", 2) != 0)
			ft_error("Usage: cd [-L|-P] [dir]");
		if (ft_strncmp(arg[t[0]], "-L", 2) == 0)
			t[1] = 1;
		if (ft_strncmp(arg[t[0]], "-P", 2) == 0)
			t[1] = 1;
		t[0]++;
	}
	return (0);
}

void	ft_echo(char ***env, char **arg)
{
	int		i;

	(void)env;
	if (arg && arg[1] && ft_strncmp(arg[1], "-n", 2))
	{
		i = 1;
		ft_write_echo(arg, &i);
		ft_putendl(arg[i]);
	}
	else if (arg && arg[1] && arg[2])
	{
		i = 2;
		ft_write_echo(arg, &i);
		ft_putstr(arg[i]);
		ft_putendl("\033[7m%\033[0m");
	}
	else if (arg && !arg[1])
		ft_putendl("");
}

void	ft_write_echo(char **arg, int *i)
{
	while (arg[(*i) + 1])
	{
		ft_putstr(arg[(*i)]);
		ft_putstr(" ");
		(*i)++;
	}
}

void	ft_exit(char ***env, char **arg)
{
	int		n;
	int		status;

	status = ft_single_ret(0, 0);
	(void)env;
	if (arg[1])
	{
		n = ft_atoi(arg[1]);
		exit(n);
	}
	else
		exit(WEXITSTATUS(status));
}
