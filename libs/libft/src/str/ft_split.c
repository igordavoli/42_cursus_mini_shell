/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:35:06 by idavoli-          #+#    #+#             */
/*   Updated: 2022/04/09 19:47:37 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	wrd_cnt(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			i++;
			while (*s != c && *s)
				s++;
		}
	}
	return (i + 1);
}

static size_t	get_wrd_size(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s == c && *s)
		s++;
	while (*s != c && *s++)
		i++;
	if (i)
		return (i + 1);
	else
		return (0);
}

static char	*get_wrd(char const *s, char c)
{
	char	*str;
	size_t	wrd_size;
	int		i;

	wrd_size = get_wrd_size(s, c);
	str = (char *)malloc(wrd_size);
	str[wrd_size - 1] = '\0';
	i = 0;
	while (*s != c && *s)
	{
		str[i++] = *s++;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	n_words;
	int		i;

	n_words = wrd_cnt(s, c);
	arr = (char **)malloc(n_words * sizeof(char **));
	arr[n_words - 1] = NULL;
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			arr[i] = get_wrd(s, c);
			while (*s != c && *s)
				s++;
			i++;
		}
	}
	return (arr);
}
