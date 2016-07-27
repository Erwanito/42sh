/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:26:44 by scaussin          #+#    #+#             */
/*   Updated: 2014/01/22 14:35:28 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int			n;
	int			i;
	int			neg;

	n = 0;
	i = 0;
	neg = 0;
	if (str == NULL)
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = 1;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n = (neg == 1) ? -n : n);
}
