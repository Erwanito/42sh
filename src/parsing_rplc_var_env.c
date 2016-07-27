/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_rplc_var_env.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 17:27:52 by scaussin          #+#    #+#             */
/*   Updated: 2014/05/25 20:54:39 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_42sh.h"
#include "libft.h"
#include <stdlib.h>

void	rplc_var_env_postfix(t_line *tree, char ***env)
{
	char	*tmp;

	if (tree->left)
		rplc_var_env_postfix(tree->left, env);
	if (tree->right)
		rplc_var_env_postfix(tree->right, env);
	if (tree->type == 1)
	{
		while (check_var_in_cmd(tree->cmd, 0) != -1)
		{
			if ((tmp = rplc(tree->cmd, env)))
				tree->cmd = tmp;
		}
		rplc_tilde(&tree->cmd, env);
	}
}

void	rplc_tilde(char **cmd, char ***env)
{
	int		i;
	char	*home;
	char	*join;
	char	*join2;

	i = 0;
	home = check_var_in_env("HOME", env);
	while (ft_strstr(&(*cmd)[i], "~")
		&& (i = check_var_in_cmd(*cmd, '~')) != -1)
	{
		(*cmd)[i] = '\0';
		join = ft_strjoin(*cmd, home);
		join2 = ft_strjoin(join, &(*cmd)[i + 1]);
		ft_strdel(&join);
		ft_strdel(cmd);
		*cmd = join2;
	}
}

char	*rplc(char *cmd, char ***env)
{
	int		begin;
	char	*var;
	char	*begin_cmd;
	char	*final_cmd;
	int		len_var;

	if ((begin = check_var_in_cmd(cmd, 0)) != -1)
	{
		len_var = begin;
		while (cmd[len_var] && cmd[len_var] != ' ')
			len_var++;
		len_var--;
		var = ft_strsub(cmd, begin + 1, len_var - begin);
		cmd[begin] = '\0';
		begin_cmd = ft_strjoin(cmd, check_var_in_env(var, env));
		final_cmd = ft_strjoin(begin_cmd, &cmd[len_var + 1]);
		ft_strdel(&var);
		ft_strdel(&begin_cmd);
		ft_strdel(&cmd);
		return (final_cmd);
	}
	return (NULL);
}

char	*check_var_in_env(char *var, char ***env)
{
	int		i;
	char	*new_var;
	int		len;

	i = 0;
	new_var = ft_strjoin(var, "=");
	len = ft_strlen(new_var);
	if (*env)
	{
		while ((*env)[i])
		{
			if (!ft_strncmp((*env)[i], new_var, len))
			{
				ft_strdel(&new_var);
				return (&(*env)[i][len]);
			}
			i++;
		}
	}
	ft_strdel(&new_var);
	return (NULL);
}

int		check_var_in_cmd(char *cmd, char c)
{
	int		i;

	i = 0;
	while (cmd && cmd[i])
	{
		if (c == 0 && cmd[i] == '$' && cmd[i + 1] != ' ' && cmd[i + 1])
			return (i);
		if (c == '~' && cmd[i] == '~'
			&& (cmd[i + 1] == '\0' || cmd[i + 1] == ' '
				|| cmd[i + 1] == ':' || cmd[i + 1] == '/')
			&& ((i > 0 && cmd[i - 1] != '~' && cmd[i - 1] == ' ') || (i == 0)))
			return (i);
		i++;
	}
	return (-1);
}
