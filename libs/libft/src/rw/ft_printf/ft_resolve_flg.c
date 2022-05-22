/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_flg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 23:38:59 by idavoli-          #+#    #+#             */
/*   Updated: 2022/04/09 20:01:15 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

t_flags	ft_flg_init(void)
{
	t_flags	flags;

	flags.f_minus = 0;
	flags.f_zero = 0;
	flags.p_dot = -1;
	flags.f_hash = 0;
	flags.f_space = -1;
	flags.f_plus = 0;
	flags.f_width = 0;
	return (flags);
}

static int	ft_is_type(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%');
}

static char	*ft_get_value(char *str, int *flag)
{
	*flag = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	return (str - 1);
}

char	*ft_flg_get(t_flags *flags, char *str)
{
	while (!ft_is_type(*str))
	{
		if (*str == '-')
			str = ft_get_value(str + 1, &flags->f_minus);
		else if (*str == '0')
			str = ft_get_value(str + 1, &flags->f_zero);
		else if (*str == '.')
			str = ft_get_value(str + 1, &flags->p_dot);
		else if (*str == '#')
			flags->f_hash = 1;
		else if (*str == ' ')
			str = ft_get_value(str + 1, &flags->f_space);
		else if (*str == '+')
			flags->f_plus = 1;
		else if (ft_isdigit(*str) && *str != '0')
			str = ft_get_value(str, &flags->f_width);
		str++;
	}
	return (str);
}
