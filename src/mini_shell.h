/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 05:16:59 by idavoli-          #+#    #+#             */
/*   Updated: 2022/05/29 04:03:05 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_SHELL_H
# define MINI_SHELL_H

# include "../libs/libft/src/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>

typedef struct s_msh
{
	int		argc;
	char	**argv;
	char	**envp;
	t_dlist	*envp_lst;
	char	*line;
	char	**splitted_line;
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

#endif
