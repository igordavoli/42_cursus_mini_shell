/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:13:29 by idavoli-          #+#    #+#             */
/*   Updated: 2022/05/21 23:59:53 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

int	echo(char **cmd)
{
	int	has_n;

	has_n = !ft_strncmp(cmd[1], "-n", 3);
	if (*cmd)
		ft_putstr_fd(cmd[1 + has_n], 1);
	if (!has_n)
		ft_putchar_fd('\n', 1);
	return (0);
}
