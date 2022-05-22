/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:07:20 by idavoli-          #+#    #+#             */
/*   Updated: 2022/04/09 19:47:37 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start < s_len)
	{
		if (s_len > len)
			sub_s = (char *)malloc(len + 1);
		else
			sub_s = (char *)malloc(s_len + 1);
		if (sub_s == NULL)
			return (NULL);
		ft_strlcpy(sub_s, &s[start], len + 1);
	}
	else
	{
		sub_s = (char *) malloc(1);
		if (sub_s == NULL)
			return (NULL);
		ft_strlcpy(sub_s, "", 1);
	}
	return (sub_s);
}
