/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cir_dlstmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 23:43:41 by idavoli-          #+#    #+#             */
/*   Updated: 2022/04/15 22:38:47 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_dlist	*ft_cir_dlstmap(t_dlist *dlst, void *(*f)(void *), void (*del)(void *))
{
	t_dlist	*new;
	t_dlist	*begin;
	t_dlist	*new_lst;

	if (dlst)
	{
		new_lst = ft_dlstnew(f(dlst->content));
		begin = dlst;
		dlst = dlst->next;
		while (1)
		{
			if (dlst == begin)
				break ;
			new = ft_dlstnew(f(dlst->content));
			if (!new)
			{
				ft_dlstclear(&new_lst, del);
				return (NULL);
			}
			ft_cir_dlstadd_back(&new_lst, new);
			dlst = dlst->next;
		}
		return (new_lst);
	}
	return (NULL);
}
