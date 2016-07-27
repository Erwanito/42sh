/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 18:42:38 by scaussin          #+#    #+#             */
/*   Updated: 2014/03/27 21:52:08 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		len1;
	int		len2;
	int		i;
	int		j;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if ((new = ft_strnew(len1 + len2 + 1)) == NULL)
		return (NULL);
	j = 0;
	while (s1 && j < len1)
		new[i++] = s1[j++];
	j = 0;
	while (s2 && j < len2)
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}
