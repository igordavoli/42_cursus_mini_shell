/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_external.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 22:48:38 by idavoli-          #+#    #+#             */
/*   Updated: 2022/05/30 23:21:37 by idavoli-         ###   ########.fr       */
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
			printf("Error: can not exec: %s", *cmd);
		ft_putchar_fd('\n', 1);
	}
	wait(NULL);
	return (0);
}
