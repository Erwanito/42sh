/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 15:41:57 by scaussin          #+#    #+#             */
/*   Updated: 2014/06/24 15:09:20 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	clean_line(char *line)
{
	int		i;

	i = 0;
	while (line && line[i])
	{
		if (line[i] == '\t')
			line[i] = ' ';
		i++;
	}
}

void	free_tab_2d(char ***tab)
{
	int		i;

	i = 0;
	while ((*tab)[i])
	{
		free((*tab)[i]);
		(*tab)[i] = NULL;
		i++;
	}
	free(*tab);
	*tab = NULL;
}

char	**strtrim_2d(char **tab)
{
	int		i;
	char	*tmp;

	i = 0;
	while (tab[i])
	{
		tmp = tab[i];
		tab[i] = ft_strtrim(tab[i]);
		free(tmp);
		i++;
	}
	return (tab);
}

int		count_char(char *line, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == c)
			count++;
		i++;
	}
	return (count);
}

int		ft_strlen_2d(char **tab)
{
	int		i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}
