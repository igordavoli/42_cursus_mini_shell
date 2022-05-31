/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 23:20:18 by idavoli-          #+#    #+#             */
/*   Updated: 2022/05/30 23:21:37 by idavoli-         ###   ########.fr       */
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
