/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 23:11:51 by ldatilio          #+#    #+#             */
/*   Updated: 2022/09/06 02:18:02 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

char	*ft_strcjoin(char *s1, char s2)
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

void	parse_line(char *line)
{
	int	i;

	if (g_msh.parsed_line)
		free(g_msh.parsed_line);
	g_msh.parsed_line = NULL;
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
