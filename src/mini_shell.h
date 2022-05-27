/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 05:16:59 by idavoli-          #+#    #+#             */
/*   Updated: 2022/05/26 22:22:51 by idavoli-         ###   ########.fr       */
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
	char	**env;
	char	*line;
	char	**splitted_line;

}	t_msh;

int		is_builtin(char *cmd);
void	execute(char **cmd);
int		exec_builtin(char **cmd);
int		echo(char **cmd);
int		pwd(void);
int		cd(char *path);

#endif
