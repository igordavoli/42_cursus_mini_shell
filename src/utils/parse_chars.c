/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 03:17:11 by ldatilio          #+#    #+#             */
/*   Updated: 2022/08/09 00:52:48 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

void	parse_variables(char *line, int *i)
{
	char	*var;

	var = NULL;
	if (line[*i + 1] == '?')
	{
		*i = *i + 1;
		var = ft_itoa(g_msh.exit_code);
		g_msh.parsed_line = ft_strjoin2(g_msh.parsed_line, var, 1, 1);
	}
	else if (ft_isdigit(line[*i + 1]))
		*i = *i + 1;
	else if (ft_isalpha(line[*i + 1]))
	{
		while (ft_isalpha(line[*i + 1]))
			var = ft_strcjoin(var, line[++*i]);
		g_msh.parsed_line = ft_strjoin2(\
			g_msh.parsed_line, ft_getenv(var), 1, 0);
		free(var);
	}
	else
		g_msh.parsed_line = ft_strcjoin(g_msh.parsed_line, line[*i]);
}

void	parse_quotes(char *line, int *i, char quote)
{
	g_msh.parsed_line = ft_strcjoin(g_msh.parsed_line, line[*i]);
	while (line[*i] != '\0')
	{
		if (quote == '\"' && line[*i] == '$')
			parse_variables(line, i);
		if (line[++*i] == quote)
		{
			g_msh.parsed_line = ft_strcjoin(g_msh.parsed_line, line[*i]);
			return ;
		}
		if (line[*i] != '\0' && line[*i] != '$')
			g_msh.parsed_line = ft_strcjoin(g_msh.parsed_line, line[*i]);
	}
	write (STDOUT_FILENO, "Error: unclosed quotes\n", 24);
	g_msh.error = 1;
	g_msh.exit_code = 1;
}

void	add_redirect(char *file, char operator)
{
	check_directory_error(file);
	if (operator == '<')
	{
		if (g_msh.file_in != NULL)
		{
			free(g_msh.file_in);
			close(g_msh.fdin);
		}
		g_msh.file_in = file;
		// open_file_input();
	}
	if (operator == '>')
	{
		g_msh.file_out = file;
		open_file_output();
	}
}

void	parse_redirect(char *line, int *i, char operator)
{
	char	*file;

	dup2(g_msh.save_stdin, STDIN_FILENO);
	file = NULL;
	*i = *i + 1;
	g_msh.operator = '\0';
	if (line[*i] == operator)
	{
		g_msh.operator = operator;
		*i = *i + 1;
	}
	while (line[*i] == ' ')
		*i = *i + 1;
	if (check_syntax_error(line[*i]))
		return ;
	while (line[*i] != '\0' && line[*i] != ' ' && !check_syntax_error(line[*i]))
	{
		file = ft_strcjoin(file, line[*i]);
		*i = *i + 1;
	}
	add_redirect(file, operator);
}
