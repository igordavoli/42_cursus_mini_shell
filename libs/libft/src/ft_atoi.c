/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 22:20:52 by idavoli-          #+#    #+#             */
/*   Updated: 2022/04/22 00:26:53 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	num;
	int	sig;

	num = 0;
	sig = 1;
	while (ft_isspace(*str))
		str++;
	if (ft_isdigit(*str) || *str == '-' || *str == '+')
	{
		if (*str == '-')
			sig = -1;
		if (*str == '+' || *str == '-')
			str++;
		while (ft_isdigit(*str))
		{
			num *= 10;
			num += *str - '0';
			str++;
		}
	}
	return (num * sig);
}
