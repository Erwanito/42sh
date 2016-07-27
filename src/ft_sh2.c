/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 17:48:17 by scaussin          #+#    #+#             */
/*   Updated: 2014/06/26 11:48:40 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "ft_42sh.h"
#include "libft.h"

void	ft_execcmd(char *tcmd, char ***env)
{
	pid_t	father;
	char	**cmd;
	int		stat_loc;

	cmd = ft_strsplit(tcmd, ' ');
	if (!ft_builtin(env, cmd))
	{
		father = fork();
		if (!father)
		{
			ft_signal_off();
			ft_execve(cmd, env);
		}
		else
		{
			waitpid(father, &stat_loc, WUNTRACED);
			ft_signal_on();
			ft_single_ret(stat_loc, 1);
		}
	}
	ft_strdel2d(&cmd);
}

void	ft_pipe(t_line *tree, char ***env, int fd[2])
{
	pid_t	father;
	pid_t	father2;

	father = fork();
	if (!father)
	{
		ft_dup(fd, 0, 1);
		ft_sh2(tree->left, env);
		exit(0);
	}
	father2 = fork();
	if (!father2)
	{
		ft_dup(fd, 1, 0);
		ft_sh2(tree->right, env);
		exit(0);
	}
	if (father || father2)
	{
		close(fd[0]);
		close(fd[1]);
		waitpid(father, NULL, 0);
		waitpid(father2, NULL, 0);
	}
}

void	ft_right(t_line *tree, char ***env, int n)
{
	pid_t	father;

	father = fork();
	if (!father)
	{
		if (ft_start_right(tree, n) == -1)
			exit(0);
		ft_sh2(tree->left, env);
		exit(0);
	}
	else
		wait(NULL);
}

void	ft_left(t_line *tree, char ***env)
{
	pid_t	father;

	father = fork();
	if (!father)
	{
		if (ft_start_left(tree) == -1)
			exit(0);
		ft_sh2(tree->left, env);
		exit(0);
	}
	else
		wait(NULL);
}

void	ft_sh2(t_line *tree, char ***newenv)
{
	int		fd[2];

	if (tree->type == 1)
		ft_execcmd(tree->cmd, newenv);
	if (tree->type == 2)
	{
		pipe(fd);
		ft_pipe(tree, newenv, fd);
	}
	if (tree->type == 3)
		ft_right(tree, newenv, 1);
	if (tree->type == 4)
		ft_left(tree, newenv);
	if (tree->type == 5)
		ft_right(tree, newenv, 2);
	if (tree->type == 7 || tree->type == 8)
		ft_logic_opp(tree, newenv);
}
