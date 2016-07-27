/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 13:14:27 by scaussin          #+#    #+#             */
/*   Updated: 2014/03/08 11:55:32 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	tmp = *alst;
	while (tmp)
	{
		del((*alst)->content, (*alst)->content_size);
		tmp = (*alst)->next;
		*alst = tmp;
	}
	ft_memdel((void**)alst);
	*alst = NULL;
}
