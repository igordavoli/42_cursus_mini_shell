/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:07:20 by idavoli-          #+#    #+#             */
/*   Updated: 2022/04/09 19:47:37 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin2(char const *s1, char const *s2, int free_s1, int free_s2)
{
	char	*bstr;
	size_t	s1len;
	size_t	s2len;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	bstr = (char *)malloc(s1len + s2len + 1);
	if (!bstr)
		return (NULL);
	ft_strlcpy(bstr, s1, s1len + 1);
	ft_strlcat(bstr, s2, s1len + s2len + 1);
	if (free_s1)
		free((char *)s1);
	if (free_s2)
		free((char *)s2);
	return (bstr);
}
