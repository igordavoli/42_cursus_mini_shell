/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 23:31:22 by idavoli-          #+#    #+#             */
/*   Updated: 2022/04/09 19:56:17 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_strjoin_f(char **s1, char *s2)
{
	char	*bstr;
	size_t	s1len;
	size_t	s2len;

	if (!(*s1) || !s2)
		return (NULL);
	s1len = 0;
	while ((*s1)[s1len])
		s1len++;
	s2len = 0;
	while (s2[s2len])
		s2len++;
	bstr = (char *)malloc(s1len + s2len + 1);
	if (!bstr)
		return (NULL);
	ft_strlcpy(bstr, *s1, s1len + 1);
	ft_strlcat(bstr, s2, s1len + s2len + 1);
	free(*s1);
	*s1 = NULL;
	return (bstr);
}

static char	*ft_substr_f(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	len_sub;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = 0;
	while (s[s_len])
		s_len++;
	len_sub = s_len - start;
	if (start <= s_len)
	{
		if (len_sub > len)
			sub = (char *)malloc(sizeof(char) * len + 1);
		else
			sub = (char *)malloc(sizeof(char) * len_sub + 1);
		if (!sub)
			return (NULL);
		ft_strlcpy(sub, &s[start], len + 1);
	}
	else
		sub = ft_strdup("");
	free(s);
	s = NULL;
	return (sub);
}

static char	*extract_line(char *buffer, char **static_buff, ssize_t read_bytes,
	int lf)
{
	char		*line;
	char		*line_end;

	if (*static_buff)
		line = ft_strjoin_f(static_buff, buffer);
	else
		line = ft_strdup(buffer);
	line_end = ft_strchr(line, '\n');
	if (line_end)
	{
		*static_buff = ft_strdup(line_end + 1);
		line = ft_substr_f(line, 0, line_end - line + lf);
		return (line);
	}
	else if (read_bytes)
	{
		*static_buff = ft_strdup(line);
		free(line);
		line = NULL;
	}
	else if (*line)
		return (line);
	free(line);
	return (NULL);
}

static char	*get_line(int fd, char *buffer, int lf)
{
	static char	*static_buff;
	char		*line;
	ssize_t		read_bytes;

	read_bytes = 1;
	line = NULL;
	while (!line && read_bytes)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(static_buff);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		line = extract_line(buffer, &static_buff, read_bytes, lf);
	}
	return (line);
}

char	*get_next_line(int fd, int lf)
{
	char		*buffer;
	char		*line;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = get_line(fd, buffer, lf);
	free(buffer);
	return (line);
}
