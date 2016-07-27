/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_logic_opp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 17:38:09 by scaussin          #+#    #+#             */
/*   Updated: 2014/06/26 18:57:32 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_42sh.h"
#include "ft_printf.h"
#include <unistd.h>

int		parse_logic_opp(char *line, t_line *tree)
{
	char	**split;
	int		*type_logic;

	type_logic = type_logic_opp(line);
	if (!(count_str(line, "||") + count_str(line, "&&")))
	{
		free(type_logic);
		return (0);
	}
	split = strtrim_2d(ft_strsplit_spe(line));
	if (count_str(line, "||") + count_str(line, "&&")
		!= ft_strlen_2d(split) - 1)
	{
		free_tab_2d(&split);
		free(type_logic);
		return (-1);
	}
	add_opp_logic(split, tree, type_logic);
	free(type_logic);
	free(split);
	return (1);
}

void	add_opp_logic(char **split, t_line *tree, int *type_logic)
{
	int		i;

	i = 0;
	while (split && split[i + 1])
	{
		add_operator(tree, split[i], split[i + 1], type_logic[i]);
		tree = tree->right;
		i++;
	}
}

int		*type_logic_opp(char *s)
{
	int		*type;
	int		i;
	int		j;

	i = 0;
	j = 0;
	type = (int *)malloc(sizeof(int) * (count_str(s, "||") +
		count_str(s, "&&")));
	while (s[i] && j < (count_str(s, "||") + count_str(s, "&&")))
	{
		while (s[i] && s[i + 1] && ((s[i] != '&' || s[i + 1] != '&') &&
				(s[i] != '|' || s[i + 1] != '|')))
			i++;
		if (s[i] == '&')
			type[j] = 8;
		else if (s[i] == '|')
			type[j] = 7;
		i += 2;
		j++;
	}
	return (type);
}

int		count_str(char *line, char *str)
{
	int				i;
	unsigned int	j;
	int				count;

	i = 0;
	count = 0;
	while (str && line && line[i])
	{
		j = 0;
		while (str[j] && str[j] == line[i])
		{
			j++;
			i++;
		}
		if (j == ft_strlen(str))
		{
			count++;
			i--;
		}
		i++;
	}
	return (count);
}

void	parse_postfix_logic(t_line *tree)
{
	int		ret_pipe;
	char	*tmp;

	if (tree->left)
		parse_postfix_logic(tree->left);
	if (tree->right)
		parse_postfix_logic(tree->right);
	if (!tree->cmd)
		return ;
	ret_pipe = parse_pipe(tree->cmd, tree);
	clean_line(tree->cmd);
	if (!ret_pipe)
	{
		tmp = tree->cmd;
		add_cmd(tree, tree->cmd);
		free(tmp);
	}
	if (ret_pipe == -1 || !parse_postfix(tree))
	{
		ft_putendl_fd("42sh: parse error near pipe", 2);
		return ;
	}
}
