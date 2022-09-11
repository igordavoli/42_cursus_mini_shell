/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 21:09:36 by ldatilio          #+#    #+#             */
/*   Updated: 2022/09/11 03:25:18 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

static	int	ft_str_isdigit(char *str)
{
	int	i;

	i = -1;
	if (str[0] != '-' || str[0] != '+')
		++i;
	while (str[++i])
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	return (1);
}

void	msh_exit(char **cmd)
{
	write (1, "exit\n", 5);
	if (cmd[1] != NULL && ft_str_isdigit(cmd[1]) == 0)
	{
		g_msh.exit_code = 2;
		ft_putstr_fd("exit: ", STDERR_FILENO);
		ft_putstr_fd(cmd[1], STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
	}
	else if (cmd[1] != NULL && cmd[2] != NULL)
	{
		g_msh.exit_code = 1;
		ft_putstr_fd("exit: too many arguments\n", STDERR_FILENO);
	}
	else if (cmd[1] != NULL && ft_str_isdigit(cmd[1]) == 1)
		g_msh.exit_code = ft_atol(cmd[1]);
	if (g_msh.exit_code < 0)
		g_msh.exit_code = 156;
	free_all();
	exit(g_msh.exit_code);
}
