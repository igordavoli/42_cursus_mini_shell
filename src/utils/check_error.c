/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 02:45:53 by ldatilio          #+#    #+#             */
/*   Updated: 2022/08/24 01:32:15 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

int	check_syntax_error(char c)
{
	if (c == '|' || c == '&' || c == ';' || c == '(' \
	|| c == ')' || c == '<' || c == '>' || c == '\0')
	{
		ft_putstr_fd("miniHell: syntax error near unexpected token `", 2);
		if (c == '\0')
			ft_putstr_fd("newline", 2);
		else
			ft_putchar_fd(c, 2);
		ft_putstr_fd("'\n", 2);
		g_msh.error = 1;
		g_msh.exit_code = 2;
		return (1);
	}
	return (0);
}

int	check_dir(char *path)
{
	struct stat	statbuf;

	if (stat(path, &statbuf) != 0)
		return (0);
	return (S_ISDIR(statbuf.st_mode));
}

void	check_directory_error(char *file)
{
	if (file == NULL)
		return ;
	if (check_dir(file) == 1 && g_msh.error == 0)
	{
		ft_putstr_fd(file, STDERR_FILENO);
		ft_putstr_fd(": Is a directory\n", STDERR_FILENO);
		g_msh.error = 1;
		g_msh.exit_code = 1;
	}
}
