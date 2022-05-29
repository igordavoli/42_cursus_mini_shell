/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 00:55:51 by idavoli-          #+#    #+#             */
/*   Updated: 2022/05/29 02:54:46 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

t_dlist	*create_list(char **strs)
{
	t_dlist	*envp_lst;

	envp_lst = NULL;
	while (*strs)
		ft_dlstadd_back(&envp_lst, ft_dlstnew((void *)ft_strdup(*strs++)));
	return (envp_lst);
}
