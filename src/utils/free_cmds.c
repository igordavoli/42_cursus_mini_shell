/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 23:49:15 by idavoli-          #+#    #+#             */
/*   Updated: 2022/08/19 03:16:28 by ldatilio         ###   ########.fr       */
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
	free_cmds(g_msh.splitted_cmds);
	free(g_msh.parsed_line);
	free(g_msh.prompt);
	ft_dlstclear(&g_msh.envp_lst, &free);
	close(g_msh.save_stdin);
	close(g_msh.save_stdout);
	close(g_msh.fd[0]);
	close(g_msh.fd[1]);
	rl_clear_history();
}
