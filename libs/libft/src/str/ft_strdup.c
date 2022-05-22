/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 00:17:25 by idavoli-          #+#    #+#             */
/*   Updated: 2022/04/09 19:47:37 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str_dup;
	size_t	size;

	size = ft_strlen(s1) + 1;
	str_dup = (char *)malloc(size);
	ft_strlcpy(str_dup, s1, size);
	return (str_dup);
}
