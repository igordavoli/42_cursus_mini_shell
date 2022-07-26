/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 23:20:18 by idavoli-          #+#    #+#             */
/*   Updated: 2022/07/26 03:57:24 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

void	execute(char **cmd)
{
	if (is_builtin(*cmd))
		exec_builtin(cmd);
	else
		exec_external(cmd);
}
