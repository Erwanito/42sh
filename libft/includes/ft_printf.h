/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 11:13:27 by scaussin          #+#    #+#             */
/*   Updated: 2014/03/27 22:57:40 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "struct_lib.h"

# define SIZE_TAB_FNCT 10

int		ft_putstr_prntf(char const *s);
void	ft_putnbr_unsgned(unsigned int n);
void	ft_putnbr_o(unsigned int n);
void	ft_putnbr_x(unsigned int n);
void	ft_putnbr_p(unsigned long n);
void	ft_putnbr_x2(unsigned int n);
int		ft_printf(const char *str, ...);
int		ft_manage_prntf(char *str, va_list ap);
int		ft_printf_d(int nbr);
int		ft_printf_s(char *str);
int		ft_printf_c(char c);
int		ft_printf_u(unsigned int nbr);
int		ft_printf_o(unsigned int nbr);
int		ft_printf_x(unsigned int nbr);
int		ft_printf_x2(unsigned int nbr);
int		ft_printf_p(unsigned long nbr);
int		ft_printf_d_va(va_list ap);
int		ft_printf_u_va(va_list ap);
int		ft_printf_o_va(va_list ap);
int		ft_printf_s_va(va_list ap);
int		ft_printf_c_va(va_list ap);
int		ft_printf_x_va(va_list ap);
int		ft_printf_x2_va(va_list ap);
int		ft_printf_p_va(va_list ap);
int		ft_printf_per100_va(va_list ap);
t_swch	*ft_init_fun_tab(void);
int		ft_match_fnct(char c, va_list ap);

#endif
