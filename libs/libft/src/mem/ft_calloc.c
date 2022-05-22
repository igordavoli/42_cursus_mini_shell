/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 03:08:40 by idavoli-          #+#    #+#             */
/*   Updated: 2022/04/09 19:51:36 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	t_size;
	void	*mem;

	t_size = count * size;
	if (t_size < 2147483647)
		mem = malloc(t_size);
	else
		return (NULL);
	if (!mem)
		return (NULL);
	ft_bzero(mem, t_size);
	return (mem);
}
