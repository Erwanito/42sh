/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 09:41:51 by scaussin          #+#    #+#             */
/*   Updated: 2014/03/26 20:56:20 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbr_tab(char *s, char c)
{
	int		i;
	int		m;

	i = 0;
	m = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			m++;
			while (s[i] != c && s[i])
				i++;
		}
		if (s[i] == c)
			i++;
	}
	return (m);
}

static char	**ft_create_tab(char **split, char *s, char c, int m)
{
	int				i;
	int				j;
	int				k;
	unsigned int	start;

	i = 0;
	j = 0;
	while (s[i] && m > 0)
	{
		k = 0;
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i])
		{
			i++;
			k++;
		}
		split[j] = ft_strsub(s, start, k);
		j++;
		m--;
	}
	split[j] = '\0';
	return (split);
}

char		**ft_strsplit(char *s, char c)
{
	int		m;
	char	**split;

	if (!s || s[0] == '\0')
		return (NULL);
	else
	{
		m = ft_nbr_tab(s, c);
		split = (char **)ft_memalloc((sizeof(char *) * (m + 10)));
		if (split == NULL)
			return (NULL);
		split = ft_create_tab(split, s, c, m);
		return (split);
	}
}
