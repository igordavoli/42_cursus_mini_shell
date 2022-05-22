/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 22:34:04 by idavoli-          #+#    #+#             */
/*   Updated: 2022/04/12 14:11:47 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_dlist	*ft_dlstlast(t_dlist *dlst)
{
	if (!dlst)
		return (0);
	while (dlst->next)
		dlst = dlst->next;
	return (dlst);
}
