/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_prtf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 16:33:22 by scaussin          #+#    #+#             */
/*   Updated: 2014/03/26 19:00:52 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_x(unsigned int n)
{
	if (n > 15)
		ft_putnbr_x(n / 16);
	if ((n % 16) + 48 > '9')
		ft_putchar((n % 16) + 87);
	else
		ft_putchar((n % 16) + 48);
}

void	ft_putnbr_x2(unsigned int n)
{
	if (n > 15)
		ft_putnbr_x2(n / 16);
	if ((n % 16) + 48 > '9')
		ft_putchar((n % 16) + 55);
	else
		ft_putchar((n % 16) + 48);
}

void	ft_putnbr_p(unsigned long n)
{
	if (n > 15)
		ft_putnbr_p(n / 16);
	if ((n % 16) + 48 > '9')
		ft_putchar((n % 16) + 87);
	else
		ft_putchar((n % 16) + 48);
}

void	ft_putnbr_unsgned(unsigned int n)
{
	if (n < 10)
	{
		n = n + 48;
		write(1, &n, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

void	ft_putnbr_o(unsigned int n)
{
	if (n > 7)
		ft_putnbr_o(n / 8);
	ft_putchar(n % 8 + 48);
}
