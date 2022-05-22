/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 23:40:25 by idavoli-          #+#    #+#             */
/*   Updated: 2022/04/12 14:51:12 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_dlstiter(t_dlist *dlst, void (*f)(void *))
{
	if (!dlst)
		return ;
	while (dlst)
	{
		f(dlst->content);
		dlst = dlst->next;
	}
}
