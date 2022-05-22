/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_dec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 03:30:00 by idavoli-          #+#    #+#             */
/*   Updated: 2022/04/09 20:01:15 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	ft_handle_flgs(int n, t_flags flags)
{
	if (flags.f_plus && n >= 0)
	{
		ft_putchar_fd('+', 1);
		return (1);
	}
	if (flags.f_space >= 0 && n >= 0)
	{
		ft_putchar_fd(' ', 1);
		return (1);
	}
	return (0);
}

static void	handle_zero_dot(int n, int *num_len, int is_neg, t_flags *flags)
{
	if (flags->f_zero > flags->p_dot && flags->p_dot < *num_len
		&& flags->p_dot != -1)
		flags->f_width = flags->f_zero;
	if (flags->f_zero > flags->p_dot && flags->p_dot > *num_len
		&& flags->p_dot != -1)
		flags->f_width = flags->f_zero - (flags->p_dot - *num_len + is_neg);
	if (!n && !flags->p_dot)
		*num_len = 0;
}

int	ft_resolve_dec(int n, t_flags flags)
{
	int	n_zeros;
	int	num_len ;
	int	len;
	int	is_neg;

	is_neg = 0;
	len = 0;
	n_zeros = 0;
	if (n < 0)
		is_neg = 1;
	num_len = ft_num_len_int(n);
	handle_zero_dot(n, &num_len, is_neg, &flags);
	len += ft_put_space(flags.f_width, num_len);
	len += ft_handle_flgs(n, flags);
	if (flags.f_zero > len + num_len)
		n_zeros = flags.f_zero - (len + num_len);
	if (flags.p_dot > (len + num_len) - 1)
		n_zeros = (flags.p_dot + is_neg) - (num_len);
	if (n || flags.p_dot)
		ft_putnbr_zero(n, n_zeros, len + num_len);
	else
		num_len = 0;
	len += n_zeros + num_len;
	len += ft_put_space(flags.f_minus, len);
	return (len);
}
