/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 13:20:00 by scaussin          #+#    #+#             */
/*   Updated: 2014/03/27 14:59:10 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "ft_42sh.h"

void	ft_dup(int fd[2], int c, int d)
{
	close(fd[c]);
	dup2(fd[d], d);
}

int		ft_open_left(t_line *tree)
{
	int		fdfile;

	if ((fdfile = open(tree->left->cmd, O_RDONLY)) == -1)
		return (ft_file_error(tree->left->cmd, 2));
	if (tree->right->type == 1)
	{
		if ((fdfile = open(tree->right->cmd, O_RDONLY)) == -1)
			return (ft_file_error(tree->right->cmd, 2));
		dup2(fdfile, 0);
		return (0);
	}
	else
		return (ft_open_left(tree->right));
}

int		ft_start_left(t_line *tree)
{
	int		fdfile;

	if (tree->right->type == 1)
	{
		if ((fdfile = open(tree->right->cmd, O_RDONLY)) == -1)
			return (ft_file_error(tree->right->cmd, 2));
		dup2(fdfile, 0);
		return (0);
	}
	else
		return (ft_open_left(tree->right));
}

int		ft_open_right(t_line *tree, int n, int flag)
{
	int		fdfile;

	if (n == 1)
		fdfile = open(tree->left->cmd, O_CREAT | O_RDWR | O_TRUNC, flag);
	else
		fdfile = open(tree->left->cmd, O_CREAT | O_RDWR | O_APPEND, flag);
	if (fdfile == -1)
		return (ft_file_error(tree->left->cmd, 1));
	close(fdfile);
	if (tree->right->type == 1)
	{
		if (n == 1)
			fdfile = open(tree->right->cmd, O_CREAT | O_RDWR | O_TRUNC, flag);
		else
			fdfile = open(tree->right->cmd, O_CREAT | O_RDWR | O_APPEND, flag);
		if (fdfile == -1)
			return (ft_file_error(tree->right->cmd, 1));
		dup2(fdfile, 1);
		return (0);
	}
	else
		return (ft_open_right(tree->right, n, flag));
}

int		ft_start_right(t_line *tree, int n)
{
	int		fdfile;
	int		flag;

	flag = (S_IRUSR + S_IWUSR + S_IRGRP + S_IROTH);
	if (tree->right->type == 1)
	{
		if (n == 1)
			fdfile = open(tree->right->cmd, O_CREAT | O_RDWR | O_TRUNC, flag);
		else
			fdfile = open(tree->right->cmd, O_CREAT | O_RDWR | O_APPEND, flag);
		if (fdfile == -1)
			return (ft_file_error(tree->right->cmd, 1));
		dup2(fdfile, 1);
		return (0);
	}
	else
		return (ft_open_right(tree->right, n, flag));
}
