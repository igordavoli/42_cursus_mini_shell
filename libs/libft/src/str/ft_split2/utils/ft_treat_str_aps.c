/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_str_aps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:09:46 by idavoli-          #+#    #+#             */
/*   Updated: 2022/03/20 21:10:11 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_get_wrd(char const *s, char c);

char	*ft_treat_str_aps(const char **s)
{
	char	*wrd;

	(*s)++;
	wrd = ft_get_wrd(*s, 39);
	while (**s != 39 && **s)
		(*s)++;
	(*s)++;
	return (wrd);
}
