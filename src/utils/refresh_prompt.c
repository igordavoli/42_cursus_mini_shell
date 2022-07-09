/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 04:26:33 by idavoli-          #+#    #+#             */
/*   Updated: 2022/07/09 20:31:29 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

static char	*get_dir(char *cwd)
{
	char	**dir;
	char	*ret;
	int		i;

	i = -1;
	if (ft_strcmp(cwd, "/"))
		return (ft_strdup("/"));
	dir = ft_split(cwd, '/');
	while (dir[++i])
		if (dir[i + 1] == NULL)
			ret = ft_strdup(dir[i]);
	free_matrix(dir);
	return (ret);
}

char	*refresh_prompt(void)
{
	char	*prompt;
	char	cwd[PATH_MAX];

	if (g_msh.prompt)
		free(g_msh.prompt);
	prompt = ft_strjoin2(ft_getenv("USER"), " at miniHell in ", 0, 0);
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		prompt = ft_strjoin2(prompt, get_dir(cwd), 1, 1);
	g_msh.prompt = ft_strjoin2(prompt, "> ", 1, 0);
	return (g_msh.prompt);
}
