/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cir_dlstiter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 23:40:25 by idavoli-          #+#    #+#             */
/*   Updated: 2022/04/16 00:44:41 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_cir_dlstiter(t_dlist *dlst, void (*f)(void *))
{
	t_dlist	*begin;

	if (!dlst)
		return ;
	begin = dlst;
	while (1)
	{
		f(dlst->content);
		dlst = dlst->next;
		if (dlst == begin)
			break ;
	}
}
