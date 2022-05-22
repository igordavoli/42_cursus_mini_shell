/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 21:51:13 by idavoli-          #+#    #+#             */
/*   Updated: 2022/04/12 15:02:07 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_dlstsize(t_dlist *dlst)
{
	int	i;

	if (!dlst)
		return (0);
	i = 1;
	while (dlst->next)
	{
		dlst = dlst->next;
		i++;
	}
	return (i);
}
