/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 00:18:22 by idavoli-          #+#    #+#             */
/*   Updated: 2022/09/06 21:19:23 by ldatilio         ###   ########.fr       */
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

void	parse_cmds(char *parsed_line)
{
	char	*sub_cmd;
	char	quote;
	int		start_cmd;
	int		i;

	quote = 0;
	start_cmd = 0;
	i = -1;
	printf("pline: %s\n", parsed_line);
	while (parsed_line[++i])
	{
		if ((parsed_line[i] == '\'' || parsed_line[i] == '\"') && quote != 0)
			quote = parsed_line[i];
		else if (parsed_line[i] == quote)
			quote = 0;
		else if (parsed_line[i] == '|' || parsed_line[i + 1] == '\0')
		{
			if (parsed_line[i + 1] == '\0')
				i++;
			sub_cmd = ft_substr(parsed_line, start_cmd, i - start_cmd);
			ft_dlstadd_back(&g_msh.cmds_lst, ft_dlstnew(split_space(sub_cmd)));
			free(sub_cmd);
			start_cmd = i + 1;
		}
	}
}
