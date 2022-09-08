/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 23:20:18 by idavoli-          #+#    #+#             */
/*   Updated: 2022/09/08 20:12:17 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

static void	parent_command(void)
{
	int	status;

	if (g_msh.last_cmd == 0)
		dup2(g_msh.fd[0], STDIN_FILENO);
	waitpid(g_msh.pid, &status, 0);
	g_msh.exit_code = WEXITSTATUS(status);
	close(g_msh.fd[1]);
	close(g_msh.fd[0]);
}

void	execute(char **cmd)
{
	if (pipe(g_msh.fd) == -1)
		exit (-1);
	if (g_msh.last_cmd == 0)
		dup2(g_msh.fd[1], STDOUT_FILENO);
	else if (g_msh.file_name && g_msh.last_cmd == 1 && g_msh.redirect == '>')
	{
		dup2(g_msh.fdout, STDOUT_FILENO);
		close(g_msh.fdout);
	}
	if (is_builtin(*cmd))
	{
		exec_builtin(cmd);
	}
	else
	{
		g_msh.pid = fork();
		if (g_msh.pid == 0)
			exec_external(cmd);
		else
			parent_command();
	}
	dup2(g_msh.fd[0], STDIN_FILENO);
	dup2(g_msh.save_stdout, STDOUT_FILENO);
	close(g_msh.fd[0]);
	close(g_msh.fd[1]);
}
