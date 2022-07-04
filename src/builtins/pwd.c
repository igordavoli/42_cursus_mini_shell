/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:51:26 by idavoli-          #+#    #+#             */
/*   Updated: 2022/06/24 01:56:21 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

int	pwd(void)
{
	char	cwd[PATH_MAX];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		ft_putstr_fd(cwd, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
	}
	else
	{
		perror("error");
		return (1);
	}
	g_msh.exit_code = 0;
	return (0);
}
