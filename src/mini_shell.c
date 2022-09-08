/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:26:38 by idavoli-          #+#    #+#             */
/*   Updated: 2022/09/08 20:12:34 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

t_msh	g_msh;

void	init_vars(int argc, char **argv, char **envp)
{
	g_msh.argc = argc;
	g_msh.argv = argv;
	g_msh.envp = envp;
	g_msh.parsed_line = NULL;
	g_msh.envp_lst = create_list(envp);
	g_msh.save_stdin = dup(STDIN_FILENO);
	g_msh.save_stdout = dup(STDOUT_FILENO);
}

void	init_vars_loop(void)
{
	g_msh.pid = 0;
	g_msh.last_cmd = 0;
	g_msh.doble_redirect = 0;
	g_msh.redirect = 0;
	g_msh.line = NULL;
	g_msh.splitted_cmds = NULL;
}

void	execute_line(void)
{
	t_dlist	*tmp;

	add_history(g_msh.line);
	parse_line(g_msh.line);
	if (g_msh.error == 0 && g_msh.parsed_line)
	{
		parse_cmds(g_msh.parsed_line);
		tmp = g_msh.cmds_lst;
		while (tmp != NULL)
		{
			if (tmp->next == NULL)
				g_msh.last_cmd = 1;
			execute((char **)tmp->content);
			tmp = tmp->next;
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	init_vars(argc, argv, envp);
	while (1)
	{
		init_vars_loop();
		signal(SIGINT, signal_handler);
		signal(SIGSEGV, signal_exit);
		g_msh.line = readline(refresh_prompt());
		if (*g_msh.line)
			execute_line();
		if (g_msh.file_name)
			free(g_msh.file_name);
		g_msh.file_name = NULL;
		free(g_msh.line);
		free_cmds_lst();
		dup2(g_msh.save_stdin, STDIN_FILENO);
		dup2(g_msh.save_stdout, STDOUT_FILENO);
	}
	return (0);
}
