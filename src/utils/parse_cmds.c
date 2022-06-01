/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 00:18:22 by idavoli-          #+#    #+#             */
/*   Updated: 2022/06/01 00:19:42 by idavoli-         ###   ########.fr       */
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

char	***parse_cmds(char *cmds)
{
	char	**splitted_part;
	char	***splitted_full;
	int		n_cmds;
	int		i;

	n_cmds = count_cmds(cmds);
	splitted_part = ft_split2(cmds, '|');
	splitted_full = (char ***)malloc(sizeof(char **) * (n_cmds + 1));
	splitted_full[n_cmds] = NULL;
	i = 0;
	while(i < n_cmds)
	{
		splitted_full[i] = ft_split2(splitted_part[i], ' ');
		i++;
	}
	return (splitted_full);
}
