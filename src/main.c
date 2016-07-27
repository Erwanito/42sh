/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 10:43:13 by scaussin          #+#    #+#             */
/*   Updated: 2014/06/24 17:47:49 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include "ft_42sh.h"
#include "get_next_line.h"
#include "libft.h"

int		main(int ac, char **av, char **env)
{
	char	*line;
	char	**newenv;

	(void)ac;
	(void)av;
	line = NULL;
	ft_signal_on();
	ft_prmpt();
	newenv = ft_strcpy_2d(env);
	while (get_next_line(0, &line))
	{
		start(line, &newenv);
		ft_prmpt();
	}
	return (0);
}

void	start(char *line, char ***env)
{
	int		i;
	t_line	*tree;
	char	**split;

	if (line && line[0])
	{
		i = 0;
		split = ft_strsplit(line, ';');
		while (split[i])
		{
			tree = new_link(0, NULL);
			manage_line(split[i], tree, env);
			free_postfix(tree);
			i++;
		}
		free_tab_2d(&split);
	}
	if (line)
		free(line);
}

void	ft_ctrl(int sig)
{
	(void)sig;
	ft_putchar('\n');
	ft_prmpt();
}

void	ft_signal_on(void)
{
	signal(SIGINT, &ft_ctrl);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGPIPE, SIG_IGN);
	signal(SIGALRM, SIG_IGN);
	signal(SIGTERM, SIG_IGN);
	signal(SIGSTOP, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGCONT, SIG_IGN);
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
}

void	ft_signal_off(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	signal(SIGPIPE, SIG_DFL);
	signal(SIGALRM, SIG_DFL);
	signal(SIGTERM, SIG_DFL);
	signal(SIGSTOP, SIG_DFL);
	signal(SIGTTIN, SIG_DFL);
	signal(SIGTTOU, SIG_DFL);
}
