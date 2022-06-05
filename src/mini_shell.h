/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 05:16:59 by idavoli-          #+#    #+#             */
/*   Updated: 2022/06/05 23:44:55 by ldatilio         ###   ########.fr       */
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

}	t_msh;

extern t_msh	g_msh;

int		is_builtin(char *cmd);
void	execute(char **cmd);
int		exec_builtin(char **cmd);
int		echo(char **cmd);
int		cd(char *path);
int		pwd(void);
int		export(char *var);
int		unset(char *env);
int		env(void);
void	msh_exit(void);
t_dlist	*create_list(char **strs);
char	*refresh_prompt(void);
void	signal_handler(int signum);
char	*get_node_value(t_dlist *node);
char	*find_cmd_path(char *cmd);
int		exec_external(char **cmd);
void	free_cmds(char ***cmds);
char	***parse_cmds(char *cmds);
char	**expand_values(char **value);

#endif
