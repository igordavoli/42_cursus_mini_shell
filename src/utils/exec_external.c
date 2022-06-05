/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_external.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 22:48:38 by idavoli-          #+#    #+#             */
/*   Updated: 2022/06/05 22:35:31 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

int	exec_external(char **cmd)
{
	pid_t	pid;

	pid = fork();
	if (!pid)
	{
		if (execve(find_cmd_path(*cmd), cmd, g_msh.envp) == -1)
			printf("Error: can not exec: %s\n", *cmd);
	}
	wait(NULL);
	if (pid == 0)
		exit(0);
	return (0);
}
