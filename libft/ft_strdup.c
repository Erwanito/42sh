/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:29:41 by scaussin          #+#    #+#             */
/*   Updated: 2014/03/08 11:46:14 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		len;
	int		i;
	char	*save;

	i = 0;
	len = ft_strlen(str);
	save = ft_strnew(len);
	while (i < len)
	{
		save[i] = str[i];
		i++;
	}
	save[i] = '\0';
	return (save);
}
