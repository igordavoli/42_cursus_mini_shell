/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstfirst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 22:34:04 by idavoli-          #+#    #+#             */
/*   Updated: 2022/04/12 14:54:04 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_dlist	*ft_dlstfirst(t_dlist *dlst)
{
	if (!dlst)
		return (0);
	while (dlst->prev)
		dlst = dlst->prev;
	return (dlst);
}
