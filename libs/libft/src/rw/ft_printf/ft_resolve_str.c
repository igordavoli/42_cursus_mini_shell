/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 04:36:29 by idavoli-          #+#    #+#             */
/*   Updated: 2022/04/09 20:01:15 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	ft_putnstr(char *str, int n)
{
	char	*s;

	s = str;
	while (n-- && *str)
		ft_putchar_fd(*str++, 1);
	return (str - s);
}

static int	ft_put_space_str(int spaces, int str_len)
{
	int	n_spaces;
	int	len;

	if (!spaces)
		return (0);
	n_spaces = spaces - str_len;
	if (n_spaces > 0)
	{
		len = n_spaces;
		while (n_spaces)
		{
			ft_putchar_fd(' ', 1);
			n_spaces--;
		}
		return (len);
	}
	return (0);
}

static int	ft_handle_f_space(int spaces, int str_len)
{
	if (spaces > str_len)
	{
		ft_put_space_str(spaces, str_len);
		return (spaces);
	}
	else
		return (0);
}

static void	ft_print_str(char *str, int *len, int n)
{
	if (n >= 0 && ft_strlen(str))
		*len = ft_putnstr(str, n);
	else
		ft_putstr_fd(str, 1);
}

int	ft_resolve_str(char *str, t_flags flags)
{
	int	str_len;
	int	len;

	if (!str)
		str = "(null)";
	str_len = ft_strlen(str);
	if (flags.p_dot != -1 && flags.p_dot < str_len)
		str_len = flags.p_dot;
	len = str_len;
	if (flags.f_width)
		len += ft_put_space(flags.f_width, str_len);
	if (flags.f_space)
		len += ft_handle_f_space(flags.f_space, str_len);
	ft_print_str(str, &len, flags.p_dot);
	if (flags.f_minus)
		len += ft_put_space(flags.f_minus, str_len);
	return (len);
}
