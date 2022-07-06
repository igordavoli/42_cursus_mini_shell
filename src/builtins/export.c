/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 02:10:00 by idavoli-          #+#    #+#             */
/*   Updated: 2022/07/06 02:51:24 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

static	int	is_duplicate_var(char *cmd)
{
	t_dlist	*head;
	t_dlist	*tmp;
	int		i;

	tmp = NULL;
	i = 0;
	while (cmd[i] != '=' && cmd[i] != '\0')
		i++;
	head = g_msh.envp_lst;
	if (head == NULL)
		return (0);
	while (head != NULL)
	{
		if (!ft_strncmp((char *)head->content, cmd, i))
		{
			tmp = head->content;
			head->content = ft_strdup(cmd);
			free(tmp);
			return (1);
		}
		head = head->next;
	}
	return (0);
}

void	export_var(char *cmd)
{
	t_dlist	*new_cmd;
	char	*mall_cmd;

	if (!is_duplicate_var(cmd))
	{
		mall_cmd = ft_strdup(cmd);
		if (mall_cmd == NULL)
			return ;
		new_cmd = ft_dlstnew((void *)mall_cmd);
		if (new_cmd == NULL)
			return ;
		else
			ft_dlstadd_back(&g_msh.envp_lst, new_cmd);
	}
}

static	int	is_valid_var(char *var)
{
	int	i;

	i = 0;
	if (!ft_isalpha(var[i]) && var[i] != '_')
		return (0);
	while (var[i] != '\0' && var[i] != '=')
	{
		if (!ft_isalnum(var[i]) && var[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

void	export(char **cmd)
{
	int	i;

	i = 0;
	g_msh.exit_code = 0;
	if (cmd[1] == NULL)
	{
		env();
		return ;
	}
	while (cmd[++i])
	{
		if (is_valid_var(cmd[i]))
			export_var(cmd[i]);
		else
		{
			ft_putstr_fd("export: `", STDERR_FILENO);
			ft_putstr_fd(cmd[i], STDERR_FILENO);
			ft_putstr_fd("\': not a valid identifier\n", STDERR_FILENO);
			g_msh.exit_code = 1;
		}
	}
}
