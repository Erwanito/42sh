/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 15:32:53 by scaussin          #+#    #+#             */
/*   Updated: 2014/06/26 19:01:57 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "ft_42sh.h"
#include <stdlib.h>

/*
**	type 0 = unknown
**	type 1 = cmd
**	type 2 = |
**	type 3 = >
**	type 4 = <
**	type 5 = >>
**	type 6 = <<
**	type 7 = ||
**	type 8 = &&
*/

void	manage_line(char *line, t_line *tree, char ***env)
{
	int		ret_logic;
	int		ret_pipe;

	ret_logic = parse_logic_opp(line, tree);
	if (ret_logic == -1)
		return (ft_putendl_fd("42sh: parse error near logic operator", 2));
	if (!ret_logic)
	{
		ret_pipe = parse_pipe(line, tree);
		clean_line(line);
		if (!ret_pipe)
			add_cmd(tree, line);
		if (ret_pipe == -1 || !parse_postfix(tree))
		{
			ft_putendl_fd("42sh: parse error near pipe", 2);
			return ;
		}
	}
	else
		parse_postfix_logic(tree);
	rplc_var_env_postfix(tree, env);
	ft_sh2(tree, env);
}

int		parse_pipe(char *line, t_line *tree)
{
	int		i;
	char	**split;

	i = 0;
	if (!line || !count_char(line, '|'))
		return (0);
	split = strtrim_2d(ft_strsplit(line, '|'));
	if (count_char(line, '|') != ft_strlen_2d(split) - 1)
	{
		free_tab_2d(&split);
		return (-1);
	}
	while (split && split[i + 1])
	{
		add_operator(tree, split[i], split[i + 1], 2);
		tree = tree->right;
		i++;
	}
	free(split);
	return (1);
}

int		parse_redirection(t_line *tree, char *key, int type)
{
	int		i;
	char	**splt;

	i = 0;
	if (!ft_strstr(tree->cmd, key))
		return (0);
	splt = strtrim_2d(ft_strsplit_str(tree->cmd, key));
	if (!check_operator(tree->cmd) || ft_strlen_2d(splt) < 2)
	{
		free_tab_2d(&splt);
		return (-1);
	}
	free(tree->cmd);
	while (splt[i + 1])
	{
		add_operator(tree, ft_strtrim(splt[i]), ft_strtrim(splt[i + 1]), type);
		tree = tree->right;
		i++;
	}
	free_tab_2d(&splt);
	return (1);
}

int		parse_postfix(t_line *tree)
{
	if (parse_redirection(tree, ">>", 5) == -1
		|| parse_redirection(tree, "<<", 6) == -1
		|| parse_redirection(tree, ">", 3) == -1
		|| parse_redirection(tree, "<", 4) == -1)
		return (0);
	if (tree->left)
	{
		if (!parse_postfix(tree->left))
			return (0);
	}
	if (tree->right)
	{
		if (!parse_postfix(tree->right))
			return (0);
	}
	return (1);
}

void	free_postfix(t_line *tree)
{
	if (tree->left)
		free_postfix(tree->left);
	if (tree->right)
		free_postfix(tree->right);
	free(tree->cmd);
	free(tree);
	ft_bzero(tree, sizeof(t_line));
}
