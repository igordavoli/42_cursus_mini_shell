/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 22:58:28 by idavoli-          #+#    #+#             */
/*   Updated: 2022/04/12 14:50:50 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_dlstdelone(t_dlist *dlst_node, void (*del)(void*))
{
	if (del)
		del(dlst_node->content);
	free(dlst_node);
	dlst_node = NULL;
}
