/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:41:46 by scaussin          #+#    #+#             */
/*   Updated: 2013/11/20 13:41:48 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned int	i;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (i < n)
	{
		if (((unsigned char *)str)[i] == (unsigned char)c)
			return (&((unsigned char *)str)[i]);
		i++;
	}
	return (NULL);
}
