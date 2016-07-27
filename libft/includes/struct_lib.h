/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_lib.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 22:50:50 by maxevra           #+#    #+#             */
/*   Updated: 2014/06/26 11:46:42 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_LIB_H
# define STRUCT_LIB_H

# include <stdarg.h>
# include <stdlib.h>

typedef struct		s_fun_switch
{
	char			c;
	int				(*fnct)(va_list);
}					t_swch;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

#endif
