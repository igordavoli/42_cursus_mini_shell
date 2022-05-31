/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 02:18:04 by idavoli-          #+#    #+#             */
/*   Updated: 2022/05/30 23:21:37 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

static char	**get_paths(void)
{
	t_dlist	*envs;

	envs = g_msh.envp_lst;
	while (ft_strncmp(get_node_value(envs), "PATH=", 5))
		envs = envs->next;
	return (ft_split(get_node_value(envs) + 5, ':'));
}

static char	*join_path(char *path, char *cmd)
{
	char	*tmp;

	tmp = ft_strjoin("/", cmd);
	return (ft_strjoin2(path, tmp, 0, 1));
}

char	*find_cmd_path(char *cmd)
{
	int		i;
	char	*whole_name;
	char	**path_list;

	path_list = get_paths();
	i = 0;
	while (path_list[i])
	{
		whole_name = join_path(path_list[i], cmd);
		if (access(whole_name, F_OK) == 0)
			return (whole_name);
		free(whole_name);
		i++;
	}
	return (NULL);
}
