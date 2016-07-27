/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:54:34 by scaussin          #+#    #+#             */
/*   Updated: 2013/11/19 18:54:36 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int	i;

	if (src == NULL)
		return (NULL);
	i = 0;
	while (((char *)src)[i] != c && i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	if (i == n)
		return (NULL);
	((char *)dest)[i] = ((char *)src)[i];
	return (&((char *)dest)[i + 1]);
}
