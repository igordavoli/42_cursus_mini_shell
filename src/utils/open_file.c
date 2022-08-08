/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 23:11:51 by ldatilio          #+#    #+#             */
/*   Updated: 2022/08/01 03:49:05 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

void	open_file_output(void)
{
	if (g_msh.file_out != NULL)
	{
		if (access(g_msh.file_out, F_OK) == -1)
			g_msh.fdout = open(g_msh.file_out, O_CREAT | O_WRONLY);
		else if (access(g_msh.file_out, F_OK) == -1 && g_msh.operator == '>')
			g_msh.fdout = open(g_msh.file_out, O_CREAT | \
				O_WRONLY | O_APPEND, 0644);
		else if (access(g_msh.file_out, F_OK) == 0 && g_msh.operator == '>')
			g_msh.fdout = open(g_msh.file_out, O_WRONLY | O_APPEND);
		else if (access(g_msh.file_out, F_OK) == 0)
			g_msh.fdout = open(g_msh.file_out, O_WRONLY | O_TRUNC);
		dup2(g_msh.fdout, STDOUT_FILENO);
		free(g_msh.file_out);
		close(g_msh.fdout);
	}
}
