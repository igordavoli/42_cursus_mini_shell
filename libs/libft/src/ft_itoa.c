/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:03:15 by idavoli-          #+#    #+#             */
/*   Updated: 2022/03/23 01:34:05 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_nbr_size(int n)
{
	int	i;

	if (n == 0)
		return (2);
	if (n == -2147483648)
		return (12);
	i = 1;
	if (n < 0)
		i++;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;

	size = ft_get_nbr_size(n);
	str = (char *)malloc(size);
	str[--size] = '\0';
	if (n == -2147483648)
	{
		n = -147483648;
		str[1] = '2';
	}
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	if (n == 0)
		str[0] = '0';
	while (size-- && n && str)
	{
		str[size] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
