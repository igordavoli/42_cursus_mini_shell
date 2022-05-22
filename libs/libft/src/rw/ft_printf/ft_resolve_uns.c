/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_uns.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 03:30:00 by idavoli-          #+#    #+#             */
/*   Updated: 2022/04/09 20:01:15 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_resolve_uns(unsigned int n, t_flags flags)
{
	int	len;
	int	n_zeros;
	int	num_len;

	len = 0;
	n_zeros = 0;
	num_len = ft_num_len(n, 10);
	ft_handle_zero_dot(n, &num_len, &flags);
	len += ft_put_space(flags.f_width, num_len);
	if (flags.f_zero > num_len)
		n_zeros = flags.f_zero - (len + num_len);
	if (flags.p_dot > num_len - 1)
		n_zeros = flags.p_dot - num_len;
	if (n_zeros < 0)
		n_zeros = 0;
	if (n || flags.p_dot)
		ft_putuns_zero(n, n_zeros);
	else
		num_len = 0;
	len += n_zeros + num_len;
	len += ft_put_space(flags.f_minus, len);
	return (len);
}
