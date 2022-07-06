/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:51:26 by idavoli-          #+#    #+#             */
/*   Updated: 2022/07/06 02:50:43 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

static	void	show_dir_error(char *cmd)
{
	ft_putstr_fd("cd: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	g_msh.exit_code = 1;
}

int	ft_strcmp(char *s1, char *s2)
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

static	void	cd_oldpwd(void)
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

static	void	chpwd(void)
{
	char	cwd[PATH_MAX];
	char	*oldpwd;
	char	*pwd;

	if (ft_getenv("PWD") == NULL)
		return ;
	getcwd(cwd, sizeof(cwd));
	oldpwd = ft_strjoin2(ft_strdup("OLDPWD="), ft_getenv("PWD"), 1, 0);
	pwd = ft_strjoin2(ft_strdup("PWD="), ft_strdup(cwd), 1, 1);
	export_var(oldpwd);
	export_var(pwd);
	free(oldpwd);
	free(pwd);
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
