/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:17:09 by idavoli-          #+#    #+#             */
/*   Updated: 2022/08/20 22:55:33 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

int	exec_builtin(char **cmd)
{
	if (g_msh.file_out == NULL && g_msh.last_cmd == 0)
		dup2(g_msh.fd[1], STDOUT_FILENO);
	if (!ft_strncmp(*cmd, "echo", 5))
		echo(cmd);
	if (!ft_strncmp(*cmd, "cd", 3))
		cd(cmd);
	if (!ft_strncmp(*cmd, "pwd", 4))
		pwd();
	if (!ft_strncmp(*cmd, "export", 7))
		export(cmd);
	if (!ft_strncmp(*cmd, "unset", 6))
		unset(cmd[1]);
	if (!ft_strncmp(*cmd, "env", 4))
		env();
	if (!ft_strncmp(*cmd, "exit", 5))
		msh_exit(cmd);
	dup2(g_msh.fd[0], STDIN_FILENO);
	dup2(g_msh.save_stdout, STDOUT_FILENO);
	close(g_msh.fd[0]);
	close(g_msh.fd[1]);
	return (0);
}
