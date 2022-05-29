/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 02:41:18 by idavoli-          #+#    #+#             */
/*   Updated: 2022/05/29 03:45:42 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

static char	*get_node_value(t_dlist *node)
{
	return ((char *)node->content);
}

static void	remove_node(t_dlist *node)
{
	if(node->next == NULL)
		node->prev->next = NULL;
	else if (node->prev == NULL)
		node->next->prev = NULL;
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	ft_dlstdelone(node, &free);
}

int	unset(char *env)
{
	t_dlist *tmp;
	int		env_len;
	char	*node_value;

	env_len = ft_strlen(env);
	tmp = g_msh.envp_lst;
	node_value = get_node_value(tmp);
	if (!ft_strncmp(node_value, env, env_len) && node_value[env_len] == '=')
	{
		g_msh.envp_lst = g_msh.envp_lst->next;
		remove_node(tmp);
		return (0);
	}
	tmp = tmp->next;
	while (tmp)
	{
		node_value = get_node_value(tmp);
		if (!ft_strncmp(node_value, env, env_len) && node_value[env_len] == '=')
		{
			remove_node(tmp);
			break ;
		}
		tmp = tmp->next;
	}
	return (0);
}
