/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:13:29 by ldatilio          #+#    #+#             */
/*   Updated: 2022/09/11 03:25:18 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

int	echo(char **cmd)
{
	int	has_n;
	int	i;

	i = 0;
	has_n = 0;
	if (!cmd[1])
		ft_putchar_fd('\n', 1);
	else
	{
		has_n = !ft_strncmp(cmd[1], "-n", 3);
		if (has_n)
			i = 1;
		while (cmd[++i])
		{
			ft_printf("%s", cmd[i]);
			if (cmd[i + 1])
				write(1, " ", 1);
		}
		if (!has_n)
			ft_putchar_fd('\n', 1);
	}
	g_msh.exit_code = 0;
	return (0);
}
