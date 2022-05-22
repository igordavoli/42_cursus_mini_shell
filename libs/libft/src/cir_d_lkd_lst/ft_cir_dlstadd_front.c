/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cir_dlstadd_front.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:45:06 by idavoli-          #+#    #+#             */
/*   Updated: 2022/04/16 18:18:54 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_cir_dlstadd_front(t_dlist **dlst, t_dlist *new)
{
	t_dlist	*last;

	if (!(*dlst))
	{
		*dlst = new;
		(*dlst)->next = *dlst;
		(*dlst)->prev = *dlst;
	}
	else
	{
		last = (*dlst)->prev;
		last->next = new;
		new->prev = last;
		(*dlst)->prev = new;
		new->next = (*dlst);
		*dlst = new;
	}
}
