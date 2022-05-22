/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 22:26:56 by idavoli-          #+#    #+#             */
/*   Updated: 2022/04/09 19:47:37 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	len;

	if (!s1)
		return (NULL);
	str = (char *)s1;
	while (*str && ft_strchr(set, *str))
		str++;
	start = str - s1;
	str = (char *)s1 + ft_strlen(s1) - 1;
	while ((str - s1) && ft_strrchr(set, *str))
		str--;
	len = (str - s1) - start + 1;
	return (ft_substr(s1, start, len));
}
