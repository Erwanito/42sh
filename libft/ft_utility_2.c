/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 14:50:46 by scaussin          #+#    #+#             */
/*   Updated: 2014/03/26 19:24:48 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

int		ft_printf_p(unsigned long nbr)
{
	int				ret;
	unsigned long	copy;

	copy = nbr;
	ret = 0;
	if (nbr == 0)
		ret++;
	while (nbr >= 1)
	{
		nbr = nbr / 16;
		ret++;
	}
	ft_putstr_prntf("0x");
	ft_putnbr_p(copy);
	return (ret + 2);
}

int		ft_printf_x2(unsigned int nbr)
{
	int		ret;
	int		copy;

	copy = nbr;
	ret = 0;
	if (nbr == 0)
		ret++;
	while (nbr >= 1)
	{
		nbr = nbr / 16;
		ret++;
	}
	ft_putnbr_x2(copy);
	return (ret);
}

int		ft_printf_x(unsigned int nbr)
{
	int		ret;
	int		copy;

	copy = nbr;
	ret = 0;
	if (nbr == 0)
		ret++;
	while (nbr >= 1)
	{
		nbr = nbr / 16;
		ret++;
	}
	ft_putnbr_x(copy);
	return (ret);
}

int		ft_putstr_prntf(char const *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
	return (i);
}
