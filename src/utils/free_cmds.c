/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 23:49:15 by idavoli-          #+#    #+#             */
/*   Updated: 2022/07/24 22:18:30 by ldatilio         ###   ########.fr       */
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

void	free_all(void)
{
	ft_dlstclear(&g_msh.envp_lst, &free);
	free_cmds(g_msh.splitted_cmds);
	free(g_msh.prompt);
	free(g_msh.parsed_line);
	rl_clear_history();
}
