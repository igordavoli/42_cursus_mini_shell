/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:26:38 by idavoli-          #+#    #+#             */
/*   Updated: 2022/08/11 03:31:43 by ldatilio         ###   ########.fr       */
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
		signal(SIGINT, signal_handler);
		signal(SIGSEGV, exit);
		dup2(g_msh.save_stdin, STDIN_FILENO);
		dup2(g_msh.save_stdout, STDOUT_FILENO);
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
					execute(g_msh.splitted_cmds[i]);
				free_cmds(g_msh.splitted_cmds);
			}
		}
		free(g_msh.line);
	}
	return (0);
}
