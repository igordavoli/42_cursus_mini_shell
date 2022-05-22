/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:35:06 by idavoli-          #+#    #+#             */
/*   Updated: 2022/04/09 19:59:35 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_get_wrd(char const *s, char c);

char	*ft_treat_str_aps(const char **s);

int		ft_wrd_cnt(char const *s, char c);

char	**ft_split2(char const *s, char c)
{
	char	**arr;
	size_t	n_words;
	int		i;

	n_words = ft_wrd_cnt(s, c);
	arr = (char **)malloc(n_words * sizeof(char **));
	arr[n_words - 1] = NULL;
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == 39)
			arr[i++] = ft_treat_str_aps(&s);
		else if (*s)
		{
			arr[i] = ft_get_wrd(s, c);
			while (*s != c && *s)
				s++;
			i++;
		}
	}
	return (arr);
}
