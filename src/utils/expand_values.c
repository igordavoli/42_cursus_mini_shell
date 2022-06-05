/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 23:18:51 by ldatilio          #+#    #+#             */
/*   Updated: 2022/06/06 00:36:12 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

char	**expand_values(char **value)
{
	int		i;
	int		j;
	char	*temp;
	
	j = 0;
	while (value[j])
	{
		i = 0;
		while (value[j][i])
		{
			if (value[j][i] == '$')
			{
				if (value[j][i + 1] == '?')
				{
					temp = value[j];
					value[j] = ft_strdup("130");
					free(temp);
					break ;
				}
			}
			i++;
		}
		j++;
	}
	return (value);
}
