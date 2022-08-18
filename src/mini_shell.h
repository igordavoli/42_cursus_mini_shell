/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 05:16:59 by idavoli-          #+#    #+#             */
/*   Updated: 2022/08/14 22:02:16 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_SHELL_H
# define MINI_SHELL_H

# include "../libs/libft/src/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <stdio.h>
# include <wait.h>

typedef struct s_msh
{
	int		argc;
	char	**argv;
	char	**envp;
	t_dlist	*envp_lst;
	char	*line;
	char	***splitted_cmds;
	char	*prompt;
	int		exit_code;
	char	*parsed_line;
	int		error;
	char	operator;
	int		fd[2];
	int		fdin;
	int		fdout;
	int		save_stdin;
	int		save_stdout;
	char	*file_out;
	char	*file_in;
	pid_t	pid;
	int		here_doc;
	int		last_cmd;
}	t_msh;

extern t_msh	g_msh;

/* ************************************************************************** */
/* ******************************** BUILTINS ******************************** */
/* ************************************************************************** */
void	cd(char **cmd);
int		echo(char **cmd);
int		env(void);
char	*ft_getenv(char *var);
void	export(char **cmd);
void	export_var(char *cmd);
void	msh_exit(char **cmd);
int		pwd(void);
int		unset(char *env);
int		ft_strcmp(char *s1, char *s2);
/* ************************************************************************** */

/* ************************************************************************** */
/* ********************************* UTILS ********************************** */
/* ************************************************************************** */
t_dlist	*create_list(char **strs);
int		exec_builtin(char **cmd);
int		exec_external(char **cmd);
void	execute(char **cmd);
char	*find_cmd_path(char *cmd);
void	free_cmds(char ***cmds);
void	free_matrix(char **matrix);
char	*get_node_value(t_dlist *node);
int		is_builtin(char *cmd);
char	***parse_cmds(char *cmds);
char	*refresh_prompt(void);
void	signal_handler(int signum);
void	free_all(void);
void	parse_line(char *line);
char	*ft_strcjoin(char *s1, char s2);
void	parse_variables(char *line, int *i);
void	parse_quotes(char *line, int *i, char quote);
void	parse_redirect(char *line, int *i, char operator);
int		check_syntax_error(char c);
void	check_directory_error(char *file);
void	open_file_output(void);
void	open_file_input(void);
/* ************************************************************************** */

#endif
