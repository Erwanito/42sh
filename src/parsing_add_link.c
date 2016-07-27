/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_add_link.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 15:29:34 by scaussin          #+#    #+#             */
/*   Updated: 2014/06/26 18:57:36 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "ft_42sh.h"

void	add_cmd(t_line *link, char *cmd)
{
	if (cmd && cmd[0])
	{
		link->type = 1;
		link->cmd = ft_strtrim(cmd);
	}
	else
	{
		link->type = 0;
		link->cmd = NULL;
	}
}

t_line	*new_link(int type, char *cmd)
{
	t_line	*new;

	if (!(new = (t_line *)malloc(sizeof(t_line))))
		return (NULL);
	ft_bzero(new, sizeof(t_line));
	new->type = type;
	new->cmd = cmd;
	return (new);
}

void	add_operator(t_line *link, char *left, char *right, int type)
{
	link->type = type;
	link->cmd = NULL;
	link->left = new_link(1, left);
	link->right = new_link(1, right);
	link->left->root = link;
	link->right->root = link;
}
