/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 04:26:33 by idavoli-          #+#    #+#             */
/*   Updated: 2022/06/26 01:26:27 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

static char *get_directory(char *cwd)
{
	char	**directory;
	int		i;
	
	directory = ft_split2(cwd, '/');
	i = -1;
	while (directory[++i])
		if (directory[i + 1] == NULL)
			return (directory[i]);
	return ("/");
}

char	*refresh_prompt(void)
{
	char	*prompt;
	char	cwd[PATH_MAX];
	char	*minihell;

	if (g_msh.prompt)
		free(g_msh.prompt);
	prompt = ft_strjoin2("\033[1;36m", ft_getenv("USER"), 0, 0);
	minihell = ft_strdup("\033[m at\033[3;1;31m miniHell\033[0;m in \033[1;34m");
	prompt = ft_strjoin2(prompt, minihell, 0, 1);
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		prompt = ft_strjoin2(prompt, get_directory(cwd), 0, 0);
	g_msh.prompt = ft_strjoin2(prompt, " \033[0;m> ", 1, 0);
	return (g_msh.prompt);
}
