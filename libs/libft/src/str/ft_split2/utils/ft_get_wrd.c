/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_wrd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:07:09 by idavoli-          #+#    #+#             */
/*   Updated: 2022/04/09 19:59:45 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft.h"

int		ft_get_wrd_size(char const *s, char c);

char	*ft_get_wrd(char const *s, char c)
{
	char	*str;
	int		wrd_size;
	int		i;

	wrd_size = ft_get_wrd_size(s, c);
	str = (char *)malloc(wrd_size);
	str[wrd_size - 1] = '\0';
	i = 0;
	while (*s != c && *s)
	{
		str[i++] = *s++;
	}
	return (str);
}
