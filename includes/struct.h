/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 16:23:41 by scaussin          #+#    #+#             */
/*   Updated: 2014/03/27 19:57:08 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_line
{
	int				type;
	char			*cmd;
	struct s_line	*root;
	struct s_line	*left;
	struct s_line	*right;
}					t_line;

typedef struct		s_ptr
{
	char			*s;
	void			(*fct)(char ***, char **);
}					t_ptr;

#endif
