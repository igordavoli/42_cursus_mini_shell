/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 00:18:22 by idavoli-          #+#    #+#             */
/*   Updated: 2022/09/06 02:18:43 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

static void	ft_remchar(char *str, char chr)
{
	int	writer;
	int	reader;

	writer = 0;
	reader = 0;
	while (str[reader])
	{
		if (str[reader] != chr)
			str[writer++] = str[reader];
		reader++;
	}
	str[writer] = 0;
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
			str[i] = 2;
			while (str[i] != quote && str[i] != '\0')
				i++;
			str[i] = 2;
		}
		else if (str[i] == ' ')
			str[i] = 1;
		i++;
	}
	ft_remchar(str, 2);
	cmd = ft_split(str, 1);
	return (cmd);
}

void	parse_pipe(char *line, int *i)
{
	char	*sub_cmd;

	sub_cmd = NULL;
	if (line[*i + 1] == '\0')
		*i = *i + 1;
	sub_cmd = ft_substr(line, g_msh.start_cmd, *i - g_msh.start_cmd);
	ft_dlstadd_back(&g_msh.cmds_lst, ft_dlstnew(split_space(sub_cmd)));
	free(sub_cmd);
	g_msh.start_cmd = *i + 1;
}
