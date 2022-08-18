/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:26:38 by idavoli-          #+#    #+#             */
/*   Updated: 2022/08/15 01:41:44 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

t_msh	g_msh;

void	init_vars(int argc, char **argv, char **envp)
{
	g_msh.argc = argc;
	g_msh.argv = argv;
	g_msh.envp = envp;
	g_msh.prompt = NULL;
	g_msh.operator = '\0';
	g_msh.envp_lst = create_list(envp);
	g_msh.exit_code = 0;
	g_msh.save_stdin = dup(STDIN_FILENO);
	g_msh.save_stdout = dup(STDOUT_FILENO);
}

int	main(int argc, char **argv, char **envp)
{
	int	i;

	init_vars(argc, argv, envp);
	while (1)
	{
		g_msh.last_cmd = 0;
		signal(SIGINT, signal_handler);
		signal(SIGSEGV, exit);
		g_msh.line = readline(refresh_prompt());
		if (*g_msh.line)
		{
			add_history(g_msh.line);
			parse_line(g_msh.line);
			if (g_msh.error == 0 && g_msh.parsed_line)
			{
				g_msh.splitted_cmds = parse_cmds(g_msh.parsed_line);					
				i = -1;
				while (g_msh.splitted_cmds[++i])
				{
					if (g_msh.splitted_cmds[i + 1] == NULL)
						g_msh.last_cmd = 1;
					execute(g_msh.splitted_cmds[i]);
				}
				free_cmds(g_msh.splitted_cmds);
			}
		}
		free(g_msh.line);
		dup2(g_msh.save_stdin, STDIN_FILENO);
		dup2(g_msh.save_stdout, STDOUT_FILENO);
	}
	return (0);
}
