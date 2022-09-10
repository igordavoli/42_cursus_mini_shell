/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:26:38 by idavoli-          #+#    #+#             */
/*   Updated: 2022/09/10 04:00:01 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

t_msh	g_msh;

static void	init_vars(int argc, char **argv, char **envp)
{
	g_msh.argc = argc;
	g_msh.argv = argv;
	g_msh.envp = envp;
	g_msh.parsed_line = NULL;
	g_msh.envp_lst = create_list(envp);
	g_msh.save_stdin = dup(STDIN_FILENO);
	g_msh.save_stdout = dup(STDOUT_FILENO);
}

static void	init_loop(void)
{
	g_msh.pid = 0;
	g_msh.last_cmd = 0;
	g_msh.doble_redirect = 0;
	g_msh.redirect = 0;
}

static void	end_loop(void)
{
	if (g_msh.file_name)
		free(g_msh.file_name);
	g_msh.file_name = NULL;
	free_cmds_lst();
	dup2(g_msh.save_stdin, STDIN_FILENO);
	dup2(g_msh.save_stdout, STDOUT_FILENO);
}

static void	execute_line(char *line)
{
	t_dlist	*tmp;

	add_history(line);
	parse_line(line);
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
	char	*line;

	init_vars(argc, argv, envp);
	while (1)
	{
		init_loop();
		signal(SIGINT, signal_handler);
		signal(SIGSEGV, signal_exit);
		line = NULL;
		line = readline(refresh_prompt());
		if (line != NULL)
			execute_line(line);
		else
		{
			write(1, "exit\n", 5);
			free_all();
			exit(0);
		}
		free(line);
		end_loop();
	}
	return (0);
}
