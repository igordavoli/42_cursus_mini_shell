/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_external.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 22:48:38 by idavoli-          #+#    #+#             */
/*   Updated: 2022/07/09 20:37:21 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

int	exec_external(char **cmd)
{
	pid_t	pid;
	char	*path;

	pid = fork();
	if (!pid)
	{
		path = find_cmd_path(*cmd);
		if (execve(path, cmd, g_msh.envp) == -1)
		{
			printf("Error: can not exec: %s\n", *cmd);
			free(path);
			free_all();
		}
	}
	wait(NULL);
	if (pid == 0)
		exit(0);
	return (0);
}
