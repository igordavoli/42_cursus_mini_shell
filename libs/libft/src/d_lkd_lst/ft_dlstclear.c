/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 23:25:16 by idavoli-          #+#    #+#             */
/*   Updated: 2022/04/16 18:13:42 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_dlstclear(t_dlist **lst, void (*del)(void*))
{
	t_dlist	*tmp;
	t_dlist	*begin;

	if (lst)
	{
		begin = *lst;
		while (*lst)
		{
			tmp = (*lst)->next;
			ft_dlstdelone(*lst, del);
			(*lst) = tmp;
			if (*lst == begin)
				break ;
		}
	}
}
