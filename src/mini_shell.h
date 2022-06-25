/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 05:16:59 by idavoli-          #+#    #+#             */
/*   Updated: 2022/06/25 23:49:30 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_SHELL_H
# define MINI_SHELL_H

# include "../libs/libft/src/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <signal.h>
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

}	t_msh;

extern t_msh	g_msh;

/* ************************************************************************** */
/* ******************************** BUILTINS ******************************** */
/* ************************************************************************** */
int		cd(char *path);
int		echo(char **cmd);
int		env(void);
int		export(char *var);
void	msh_exit(char **cmd);
int		pwd(void);
int		unset(char *env);
/* ************************************************************************** */

/* ************************************************************************** */
/* ********************************* UTILS ********************************** */
/* ************************************************************************** */
t_dlist	*create_list(char **strs);
int		exec_builtin(char **cmd);
int		exec_external(char **cmd);
void	execute(char **cmd);
char	**expand_values(char **value);
char	*find_cmd_path(char *cmd);
void	free_cmds(char ***cmds);
char	*get_node_value(t_dlist *node);
int		is_builtin(char *cmd);
char	***parse_cmds(char *cmds);
char	*refresh_prompt(void);
void	signal_handler(int signum);
/* ************************************************************************** */

#endif
