/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:26:38 by idavoli-          #+#    #+#             */
/*   Updated: 2022/06/05 22:34:45 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

t_msh	g_msh;

int	main(int argc, char **argv, char **envp)
{
	int	i;

	g_msh.argc = argc;
	g_msh.argv = argv;
	g_msh.envp = envp;
	g_msh.prompt = NULL;
	g_msh.envp_lst = create_list(envp);
	while (1)
	{
		signal(SIGINT, signal_handler);
		signal(SIGSEGV, exit);
		g_msh.line = readline(refresh_prompt());
		if (*g_msh.line)
		{
			add_history(g_msh.line);
			g_msh.splitted_cmds = parse_cmds(g_msh.line);
			i = -1;
			while (g_msh.splitted_cmds[++i])
				execute(g_msh.splitted_cmds[i]);
			free(g_msh.line);
			free_cmds(g_msh.splitted_cmds);
		}
	}
	return (0);
}
