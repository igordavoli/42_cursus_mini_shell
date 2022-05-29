/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 21:09:36 by idavoli-          #+#    #+#             */
/*   Updated: 2022/05/29 01:20:09 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

void	msh_exit(void)
{
	ft_lstclear(&g_msh.envp_lst, &free);
	ft_free_ptrs((void *)g_msh.splitted_line);
	exit(0);
}
