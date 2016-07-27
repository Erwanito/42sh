/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 11:08:08 by scaussin          #+#    #+#             */
/*   Updated: 2014/03/24 14:51:41 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *dest, const char *src)
{
	int		i;
	int		y;
	int		u;

	i = 0;
	if (src[0] == '\0')
		return (((char *)dest));
	while (dest && dest[i])
	{
		if (dest[i] == src[0])
		{
			u = i;
			y = 0;
			while (dest[u] && src[y] && dest[u] == src[y])
			{
				u++;
				y++;
			}
			if (dest[u - 1] == src[y - 1] && !(src[y]))
				return (&((char *)dest)[i]);
		}
		i++;
	}
	return (NULL);
}
