/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 13:21:10 by scaussin          #+#    #+#             */
/*   Updated: 2014/01/12 16:40:59 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *dest, const char *src, size_t n)
{
	unsigned int	i;
	unsigned int	y;
	unsigned int	u;

	i = 0;
	if (src[0] == '\0')
		return ((char *)dest);
	while (i < n && dest[i])
	{
		y = 0;
		if (dest[i] == src[0])
		{
			u = i;
			y = 0;
			while (y < (n - i) && src[y] && dest[u] == src[y])
			{
				u++;
				y++;
			}
			if (dest[u - 1] == src[y - 1] && src[y] == '\0')
				return (&((char *)dest)[i]);
		}
		i++;
	}
	return (NULL);
}
