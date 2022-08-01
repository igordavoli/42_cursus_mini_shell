/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 00:18:22 by idavoli-          #+#    #+#             */
/*   Updated: 2022/08/01 00:19:28 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

static int	count_cmds(char *cmds)
{
	int	n_cmds;

	n_cmds = 1;
	while (*cmds)
		if (*cmds++ == '|')
			n_cmds++;
	return (n_cmds);
}

static char	**split_space(char *str)
{
	int		i;
	char	**cmd;
	char	quote;

	quote = '\0';
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			quote = str[i];
			str[i] = 1;
			while (str[i] != quote && str[i] != '\0')
				i++;
			str[i] = 1;
		}
		else if (str[i] == ' ')
			str[i] = 1;
		i++;
	}
	cmd = ft_split(str, 1);
	return (cmd);
}

char	***parse_cmds(char *cmds)
{
	char	**splitted_part;
	char	***splitted_full;
	int		n_cmds;
	int		i;

	n_cmds = count_cmds(cmds);
	if (n_cmds > 1)
		splitted_part = ft_split(cmds, '|');
	else
		splitted_part = &cmds;
	splitted_full = (char ***)malloc(sizeof(char **) * (n_cmds + 1));
	splitted_full[n_cmds] = NULL;
	i = 0;
	while (i < n_cmds)
	{
		splitted_full[i] = split_space(splitted_part[i]);
		i++;
	}
	return (splitted_full);
}
