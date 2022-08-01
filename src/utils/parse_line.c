/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 23:11:51 by ldatilio          #+#    #+#             */
/*   Updated: 2022/08/01 03:20:22 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

static	char	*ft_strcjoin(char *s1, char s2)
{
	char	*s;
	int		count;

	count = -1;
	if (s2 == '\0')
		return (s1);
	if (s1 == NULL)
	{
		s = malloc (2 * sizeof(char));
		s[0] = s2;
		s[1] = '\0';
	}
	else
	{
		s = malloc ((ft_strlen(s1) + 2) * sizeof(char));
		if (s == NULL)
			return (NULL);
		while (s1[++count] != '\0')
			s[count] = s1[count];
		s[count++] = s2;
		s[count] = '\0';
	}
	free (s1);
	return (s);
}

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

int	check_syntax_error(char c)
{
	if (c == '|' || c == '&' || c == ';' || c == '(' \
	|| c == ')' || c == '<' || c == '>' || c == '\0')
	{
		ft_putstr_fd("miniHell: syntax error near unexpected token `", 2);
		if (c == '\0')
			ft_putstr_fd("newline", 2);
		else
			ft_putchar_fd(c, 2);
		ft_putstr_fd("'\n", 2);
		g_msh.error = 1;
		g_msh.exit_code = 2;
		return (1);
	}
	return (0);
}

void	parse_redirect(char *line, int *i, char operator)
{
	char	*file;

	file = NULL;
	*i = *i + 1;
	if (line[*i] == operator)
	{
		g_msh.operator = operator;
		*i = *i + 1;
	}
	while (line[*i] == ' ')
		*i = *i + 1;
	if (check_syntax_error(line[*i]))
		return ;
	while (line[*i] != '\0' && ft_isalnum(line[*i]))
	{
		file = ft_strcjoin(file, line[*i]);
		*i = *i + 1;
	}
	free(file);
}

static void	parse_loop(char *line)
{
	int	i;

	i = -1;
	g_msh.error = 0;
	while (line[++i] != '\0')
	{
		if (line[i] == '\"' || line[i] == '\'')
			parse_quotes(line, &i, line[i]);
		else if (line[i] == '$')
			parse_variables(line, &i);
		else if (line[i] == '<' || line[i] == '>')
			parse_redirect(line, &i, line[i]);
		else if (line[i] != '\0')
			g_msh.parsed_line = ft_strcjoin(g_msh.parsed_line, line[i]);
		if (g_msh.error == 1 || line[i] == '\0')
			return ;
	}
}

void	parse_line(char *line)
{
	if (g_msh.parsed_line)
		free(g_msh.parsed_line);
	g_msh.parsed_line = NULL;
	parse_loop(line);
}
