/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_split_logic_opp.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 14:13:54 by scaussin          #+#    #+#             */
/*   Updated: 2014/06/24 20:04:08 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "ft_42sh.h"
#include "libft.h"

static void	chr_opp(char **split, char *s)
{
	int start;
	int end;
	int i;
	int	j;

	start = 0;
	end = 0;
	i = 0;
	j = 0;
	while (s[i] && j < count_str(s, "||") + count_str(s, "&&") + 1)
	{
		start = i;
		while (s[i] && s[i + 1] && ((s[i] != '&' || s[i + 1] != '&') &&
				(s[i] != '|' || s[i + 1] != '|')))
			i++;
		end = (!s[i + 1]) ? i + 1 : i;
		split[j] = ft_strsub(s, start, end - start);
		j++;
		i += 2;
	}
	split[j] = '\0';
}

char		**ft_strsplit_spe(char *s)
{
	int		m;
	char	**split;

	if (!s || s[0] == '\0')
		return (NULL);
	else
	{
		m = count_str(s, "||") + count_str(s, "&&") + 1;
		split = (char **)malloc((sizeof(char *) * (m + 1)));
		if (split == NULL)
			return (NULL);
		chr_opp(split, s);
		return (split);
	}
}
