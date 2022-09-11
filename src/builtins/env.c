/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 01:59:00 by ldatilio          #+#    #+#             */
/*   Updated: 2022/09/11 03:25:18 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

char	*ft_getenv(char *var)
{
	t_dlist	*head;
	char	*tmp;

	head = g_msh.envp_lst;
	while (head->next != NULL)
	{
		head = head->next;
		tmp = head->content;
		if (!ft_strncmp(head->content, var, ft_strlen(var)) \
		&& !ft_strncmp(tmp + ft_strlen(var), "=", 1))
			return (head->content + ft_strlen(var) + 1);
	}
	return ("\0");
}

static void	print(void *varenv)
{
	printf("%s\n", (char *)varenv);
}

int	env(void)
{
	ft_dlstiter(g_msh.envp_lst, &print);
	return (0);
}
