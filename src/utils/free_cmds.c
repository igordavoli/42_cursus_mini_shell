/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 23:49:15 by idavoli-          #+#    #+#             */
/*   Updated: 2022/05/31 23:50:45 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

void	free_cmds(char ***cmds)
{
	int	i;
	int	j;

	if (cmds)
	{
		i = 0;
		while (cmds[i])
		{
			j = 0;
			while (cmds[i][j])
				free(cmds[i][j++]);
			free(cmds[i]);
			i++;
		}
		free(cmds);
	}
}
