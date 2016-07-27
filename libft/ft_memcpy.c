/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:31:22 by scaussin          #+#    #+#             */
/*   Updated: 2014/01/09 13:59:09 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dest1;
	const char	*src1;

	dest1 = (char *)dest;
	src1 = (char *)src;
	while (n--)
	{
		*dest1 = *src1;
		dest1++;
		src1++;
	}
	return (dest);
}
