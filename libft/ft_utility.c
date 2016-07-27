/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 14:46:15 by scaussin          #+#    #+#             */
/*   Updated: 2014/03/14 15:10:57 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_printf_s(char *str)
{
	if (str == NULL)
		return (ft_putstr_prntf("(null)"));
	ft_putstr_prntf(str);
	return (ft_strlen(str));
}

int		ft_printf_u(unsigned int nbr)
{
	int				ret;
	unsigned int	copy;

	copy = nbr;
	ret = 0;
	if (nbr == 0)
		ret++;
	while (nbr >= 1)
	{
		nbr = nbr / 10;
		ret++;
	}
	ft_putnbr_unsgned(copy);
	return (ret);
}

int		ft_printf_o(unsigned int nbr)
{
	int		ret;
	int		copy;

	copy = nbr;
	ret = 0;
	if (nbr <= 0)
	{
		ft_putstr_prntf("0");
		return (1);
	}
	while (nbr >= 1)
	{
		nbr = nbr / 8;
		ret++;
	}
	ft_putnbr_o(copy);
	return (ret);
}

int		ft_printf_d(int nbr)
{
	int		ret;
	int		copy;

	copy = nbr;
	ret = 0;
	if (nbr <= 0)
		ret++;
	while (nbr >= 1 || nbr <= -1)
	{
		nbr = nbr / 10;
		ret++;
	}
	ft_putnbr(copy);
	return (ret);
}

int		ft_printf_c(char c)
{
	ft_putchar(c);
	return (1);
}
