/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 18:59:46 by scaussin          #+#    #+#             */
/*   Updated: 2014/06/26 17:35:09 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*a;
	int		y;
	int		i;
	int		start;

	i = 0;
	if (s == NULL)
		return (NULL);
	y = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while ((s[y - 1] == ' ' || s[y - 1] == '\t' || s[y - 1] == '\n') && y > 0)
		y--;
	start = (i > y) ? 0 : i;
	if (y - start == 0 || !(a = ft_strnew(y - start)))
		return (NULL);
	i = 0;
	while (i < y - start)
	{
		a[i] = s[start + i];
		i++;
	}
	a[i] = '\0';
	return (a);
}
