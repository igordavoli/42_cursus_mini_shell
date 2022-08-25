/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:17:09 by idavoli-          #+#    #+#             */
/*   Updated: 2022/08/25 03:37:47 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

int	is_builtin(char *cmd)
{
	if (cmd == NULL)
		return (0);
	if (!ft_strncmp(cmd, "echo", 5)
		|| !ft_strncmp(cmd, "cd", 3)
		|| !ft_strncmp(cmd, "pwd", 4)
		|| !ft_strncmp(cmd, "export", 7)
		|| !ft_strncmp(cmd, "unset", 6)
		|| !ft_strncmp(cmd, "env", 4)
		|| !ft_strncmp(cmd, "exit", 5))
		return (1);
	return (0);
}

int	exec_builtin(char **cmd)
{
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
	return (0);
}
