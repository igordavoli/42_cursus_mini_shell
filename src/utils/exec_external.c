/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_external.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 22:48:38 by ldatilio          #+#    #+#             */
/*   Updated: 2022/09/11 03:25:18 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

int	exec_external(char **cmd)
{
	char	*path;

	path = NULL;
	close(g_msh.fd[0]);
	if (g_msh.file_name == NULL && g_msh.last_cmd == 0)
		dup2(g_msh.fd[1], STDOUT_FILENO);
	close(g_msh.fd[1]);
	close(g_msh.save_stdin);
	close(g_msh.save_stdout);
	path = find_cmd_path(*cmd);
	if (*cmd == NULL)
		;
	else if (path == NULL)
		printf("Error: can not exec: %s\n", *cmd);
	else
		execve(path, cmd, g_msh.envp);
	free(path);
	free_all();
	exit(1);
	return (0);
}
