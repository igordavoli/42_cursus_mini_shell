/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:26:38 by idavoli-          #+#    #+#             */
/*   Updated: 2022/05/29 04:26:18 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

t_msh	g_msh;

int	main(int argc, char **argv, char **envp)
{
	g_msh.argc = argc;
	g_msh.argv = argv;
	g_msh.envp = envp;
	g_msh.prompt = NULL;
	g_msh.envp_lst = create_list(envp);
	while (1)
	{
		g_msh.line = readline(refresh_prompt());
		if (*g_msh.line)
		{
			add_history(g_msh.line);
			g_msh.splitted_line = ft_split2(g_msh.line, ' ');
			execute(g_msh.splitted_line);
			free(g_msh.line);
			ft_free_ptrs((void **)g_msh.splitted_line);
		}
	}
	return (0);
}
