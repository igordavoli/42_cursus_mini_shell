/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 00:55:51 by idavoli-          #+#    #+#             */
/*   Updated: 2022/05/29 00:56:03 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

t_list	*create_list(char **strs)
{
	t_list	*envp_lst;

	envp_lst = NULL;
	while (*strs)
		ft_lstadd_back(&envp_lst, ft_lstnew((void *)ft_strdup(*strs++)));
	return (envp_lst);
}
