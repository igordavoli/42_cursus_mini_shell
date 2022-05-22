/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 03:30:00 by idavoli-          #+#    #+#             */
/*   Updated: 2022/04/09 20:01:15 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void	ft_handle_zeros(int num_len, int len, t_flags *flags, int *n_zeros)
{
	if (flags->f_zero > num_len)
		*n_zeros = (flags->f_zero - num_len);
	if (flags->p_dot > len - 1)
		*n_zeros = flags->p_dot - num_len ;
	if (*n_zeros < 0)
		*n_zeros = 0;
}

static int	ft_handle_hash(int n, int hash, int is_upper)
{
	if (hash && n)
	{
		if (is_upper)
			ft_putstr_fd("0X", 1);
		else
			ft_putstr_fd("0x", 1);
		return (2);
	}
	return (0);
}

int	ft_resolve_hex(unsigned long long n, int is_upper, t_flags flags)
{
	int	len;
	int	n_zeros;
	int	num_len;

	len = 0;
	n_zeros = 0;
	num_len = ft_num_len(n, 16);
	ft_handle_zero_dot(n, &num_len, &flags);
	ft_handle_zeros(num_len, len, &flags, &n_zeros);
	len += ft_put_space(flags.f_width, num_len);
	num_len += ft_handle_hash(n, flags.f_hash, is_upper);
	if (n || flags.p_dot)
		ft_putnbr_hex(n, is_upper, n_zeros);
	else
		num_len = 0;
	len += n_zeros + num_len;
	len += ft_put_space(flags.f_minus, len);
	return (len);
}
