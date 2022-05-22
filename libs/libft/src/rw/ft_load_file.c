/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 01:32:20 by idavoli-          #+#    #+#             */
/*   Updated: 2022/04/09 19:56:17 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_load_file(int fd)
{
	int		i;
	char	*filecontent;
	char	*swp;

	i = 0;
	while (1)
	{
		swp = get_next_line(fd, 1);
		if (swp == NULL)
			break ;
		filecontent = ft_strjoin2(filecontent, swp, 1, 1);
		i++;
	}
	return (filecontent);
}
