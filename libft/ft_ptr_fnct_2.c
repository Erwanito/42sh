/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_fnct_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 17:51:46 by scaussin          #+#    #+#             */
/*   Updated: 2014/03/26 19:24:34 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_printf_x_va(va_list ap)
{
	return (ft_printf_x(va_arg(ap, unsigned int)));
}

int		ft_printf_x2_va(va_list ap)
{
	return (ft_printf_x2(va_arg(ap, unsigned int)));
}

int		ft_printf_d_va(va_list ap)
{
	return (ft_printf_d(va_arg(ap, int)));
}

int		ft_printf_per100_va(va_list ap)
{
	ap = ap + 0;
	return (ft_printf_c('%'));
}
