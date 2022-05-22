/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wrd_cnt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:04:59 by idavoli-          #+#    #+#             */
/*   Updated: 2022/03/20 21:17:29 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_count_aps(const char **s);

int	ft_wrd_cnt(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == 39)
			ft_count_aps(&s);
		while (*s == c)
			s++;
		if (*s)
		{
			i++;
			while (*s != c && *s != 39 && *s)
				s++;
		}
	}
	return (i + 1);
}
