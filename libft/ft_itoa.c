/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 13:22:19 by scaussin          #+#    #+#             */
/*   Updated: 2014/03/26 18:57:35 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	if (n < 0)
	{
		n = -n;
		return (1 + ft_len(n));
	}
	if (n < 10)
		return (1);
	n = n / 10;
	return (1 + ft_len(n));
}

static void	ft_putnbr2(int n, char *str, int *ptri)
{
	if (n < 0)
	{
		str[0] = '-';
		(*ptri)++;
		n = -n;
	}
	if (n < 10)
	{
		str[*ptri] = n + 48;
		(*ptri)++;
	}
	else
	{
		ft_putnbr2(n / 10, str, ptri);
		ft_putnbr2(n % 10, str, ptri);
	}
}

char		*ft_itoa(int n)
{
	char	*str;
	int		*ptri;
	int		i;

	i = 0;
	ptri = &i;
	if (n == -2147483648)
	{
		str = ft_strnew(12);
		if (str == NULL)
			return (NULL);
		ft_strclr(str);
		return (ft_strcpy(str, "-2147483648\0"));
	}
	str = ft_strnew(ft_len(n) + 1);
	if (str == NULL)
		return (NULL);
	ft_strclr(str);
	ft_putnbr2(n, str, ptri);
	str[ft_len(n)] = '\0';
	return (str);
}
