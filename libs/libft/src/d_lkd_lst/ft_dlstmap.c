/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 23:43:41 by idavoli-          #+#    #+#             */
/*   Updated: 2022/04/12 15:00:19 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_dlist	*ft_dlstmap(t_dlist *dlst, void *(*f)(void *), void (*del)(void *))
{
	t_dlist	*new;
	t_dlist	*begin;

	if (dlst)
	{
		begin = ft_dlstnew(f(dlst->content));
		if (!begin)
			return (NULL);
		dlst = dlst->next;
		while (dlst)
		{
			new = ft_dlstnew(f(dlst->content));
			if (!new)
			{
				ft_dlstclear(&begin, del);
				return (NULL);
			}
			ft_dlstadd_back(&begin, new);
			dlst = dlst->next;
		}
		return (begin);
	}
	return (NULL);
}
