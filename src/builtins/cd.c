/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:51:26 by idavoli-          #+#    #+#             */
/*   Updated: 2022/07/03 22:00:37 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

static	void show_dir_error(char *cmd)
{
	ft_putstr_fd("cd: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	g_msh.exit_code = 1;
}

static	int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = -1;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (s1[++i] && s2[i])
		if (s1[i] != s2[i])
			return (0);
	return (1);
}

static	void	cd_oldpwd()
{
	if (ft_getenv("OLDPWD") == NULL)
	{
		ft_putstr_fd("cd: OLDPWD not set\n", STDERR_FILENO);
		return ;
	}
	chdir(ft_getenv("OLDPWD"));
	ft_putstr_fd(ft_getenv("OLDPWD"), STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
}

static	void	chpwd()
{
	char	cwd[PATH_MAX];
	
	if (ft_getenv("PWD") == NULL)
		return ;
	getcwd(cwd, sizeof(cwd));
	export_var(ft_strjoin(ft_strdup("OLDPWD="), ft_getenv("PWD")));
	export_var(ft_strjoin(ft_strdup("PWD="), ft_strdup(cwd)));
}

void	cd(char **cmd)
{
	g_msh.exit_code = 0;
	if (cmd[1] == NULL || ft_strcmp(cmd[1], "~"))
	{
		if (ft_getenv("HOME") == NULL)
			return ;
		chdir(ft_getenv("HOME"));
		chpwd();
	}
	else if (cmd[2] != NULL)
	{
		g_msh.exit_code = 1;
		ft_putstr_fd("cd: too many arguments\n", STDERR_FILENO);
	}
	else
	{
		if (ft_strcmp(cmd[1], "-"))
			cd_oldpwd();
		else if (chdir(cmd[1]) == -1)
			show_dir_error(cmd[1]);
		chpwd();
	}
}
