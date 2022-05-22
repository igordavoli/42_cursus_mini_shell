/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cir_dlstadd_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 22:45:08 by idavoli-          #+#    #+#             */
/*   Updated: 2022/04/15 22:36:33 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_cir_dlstadd_back(t_dlist **dlst, t_dlist *new)
{
	t_dlist	*last;

	if (!(*dlst))
		*dlst = new;
	else
	{
		last = (*dlst)->prev;
		last->next = new;
		new->prev = last;
		(*dlst)->prev = new;
		new->next = (*dlst);
	}
}
