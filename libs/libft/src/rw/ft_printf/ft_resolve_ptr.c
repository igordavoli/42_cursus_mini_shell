/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 03:30:00 by idavoli-          #+#    #+#             */
/*   Updated: 2022/04/09 20:01:15 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_ptrlen(unsigned long long ptr)
{
	int	i;

	i = 3;
	ptr /= 16;
	while (ptr)
	{
		i++;
		ptr /= 16;
	}
	return (i);
}

int	ft_resolve_ptr(unsigned long long ptr, t_flags flags)
{
	int	len;
	int	ptr_len;

	ptr_len = ft_ptrlen(ptr);
	len = ptr_len;
	if (flags.f_width)
		len += ft_put_space(flags.f_width, ptr_len);
	ft_putstr_fd("0x", 1);
	ft_putnbr_hex(ptr, 0, 0);
	len += ft_put_space(flags.f_minus, ptr_len);
	return (len);
}
