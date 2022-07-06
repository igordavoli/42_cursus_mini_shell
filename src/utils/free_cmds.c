/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 23:49:15 by idavoli-          #+#    #+#             */
/*   Updated: 2022/07/06 03:07:39 by ldatilio         ###   ########.fr       */
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

void	free_matrix(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i] != NULL)
		free(matrix[i]);
	free(matrix);
}
