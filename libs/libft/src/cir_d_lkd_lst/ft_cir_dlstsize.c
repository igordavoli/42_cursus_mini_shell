/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cir_dlstsize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 21:51:13 by idavoli-          #+#    #+#             */
/*   Updated: 2022/04/15 22:39:09 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_cir_dlstsize(t_dlist *dlst)
{
	int		i;
	t_dlist	*begin;

	if (!dlst)
		return (0);
	begin = dlst;
	i = 1;
	while (1)
	{
		dlst = dlst->next;
		if (dlst == begin)
			break ;
		i++;
	}
	return (i);
}
