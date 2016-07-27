/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_split_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 14:05:56 by scaussin          #+#    #+#             */
/*   Updated: 2014/03/27 16:34:46 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_42sh.h"
#include "ft_printf.h"

int		ft_nbr_tab(char *s, char *c)
{
	int		i;
	int		m;

	i = 0;
	m = 0;
	while (s[i])
	{
		if (ft_strncmp(&s[i], c, ft_strlen(c)))
		{
			m++;
			while (ft_strncmp(&s[i], c, ft_strlen(c)) && s[i])
				i++;
		}
		else
			i += ft_strlen(c);
	}
	return (m);
}

char	**ft_create_tab(char **split, char *s, char *c, int m)
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
		while (!ft_strncmp(&s[i], c, ft_strlen(c)))
			i += ft_strlen(c);
		start = i;
		while (ft_strncmp(&s[i], c, ft_strlen(c)) && s[i])
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

char	**ft_strsplit_str(char *s, char *c)
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
