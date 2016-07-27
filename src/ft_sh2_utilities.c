/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh2_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 17:51:03 by scaussin          #+#    #+#             */
/*   Updated: 2014/06/26 11:54:08 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_42sh.h"
#include "libft.h"

char	**ft_strcpy_2d(char **str)
{
	char	**newstr;
	int		i;

	i = 0;
	while (str[i])
		i++;
	newstr = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (str[i])
	{
		newstr[i] = ft_strdup(str[i]);
		i++;
	}
	newstr[i] = NULL;
	return (newstr);
}

void	ft_strdel2d(char ***str)
{
	int		i;

	i = 0;
	if (*str)
	{
		while ((*str)[i])
		{
			ft_strdel(&(*str)[i]);
			i++;
		}
		free((*str));
	}
}

int		ft_single_ret(int newret, int f)
{
	static int	ret = 0;

	if (f == 1)
		ret = newret;
	return (ret);
}

int		ft_file_error(char *file, int r)
{
	if (file)
	{
		ft_putstr_fd("ft_sh2: ", 2);
		ft_putstr_fd(file, 2);
		if (r == 2 && access(file, F_OK) == -1)
		{
			ft_putstr_fd(": No such file or directory\n", 2);
			return (-1);
		}
		if (r == 1 && access(file, W_OK) == -1)
		{
			ft_putstr_fd(": Permission denied\n", 2);
			return (-1);
		}
		if (r == 2 && access(file, R_OK) == -1)
		{
			ft_putstr_fd(": Permission denied\n", 2);
			return (-1);
		}
	}
	return (-1);
}

void	ft_logic_opp(t_line *tree, char ***env)
{
	int		status;

	ft_sh2(tree->left, env);
	status = ft_single_ret(0, 0);
	if (WEXITSTATUS(status) == 0)
	{
		if (tree->type == 8)
			ft_sh2(tree->right, env);
		else
			return ;
	}
	else
	{
		if (tree->type == 7)
			ft_sh2(tree->right, env);
		else
			return ;
	}
}
