/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:33:10 by scaussin          #+#    #+#             */
/*   Updated: 2013/12/06 11:46:58 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	lendest;
	int				lensrc;
	int				i;
	int				result;

	i = 0;
	lensrc = ft_strlen(src);
	lendest = ft_strlen(dest);
	result = size - lendest - 1;
	while (i < result)
	{
		dest[lendest + i] = src[i];
		i++;
	}
	dest[lendest + i] = '\0';
	if (size < lendest)
		return (lensrc + size);
	return (lendest + lensrc);
}
