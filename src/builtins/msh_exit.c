/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 21:09:36 by idavoli-          #+#    #+#             */
/*   Updated: 2022/05/29 04:04:45 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

void	msh_exit(void)
{
	ft_dlstclear(&g_msh.envp_lst, &free);
	ft_free_ptrs((void *)g_msh.splitted_line);
	free(g_msh.prompt);
	exit(0);
}
