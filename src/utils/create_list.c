/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 00:55:51 by idavoli-          #+#    #+#             */
/*   Updated: 2022/08/24 01:42:30 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

t_dlist	*create_list(char **strs)
{
	t_dlist	*envp_lst;
	int		i;

	envp_lst = NULL;
	i = -1;
	while (strs[++i])
		if (ft_strnstr(strs[i], "WORKSPACE", ft_strlen(strs[i])) == NULL)
			ft_dlstadd_back(&envp_lst, ft_dlstnew((void *)ft_strdup(strs[i])));
	return (envp_lst);
}

char	*get_node_value(t_dlist *node)
{
	return ((char *)node->content);
}
