/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 01:59:00 by idavoli-          #+#    #+#             */
/*   Updated: 2022/07/05 04:22:33 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

char	*ft_getenv(char *var)
{
	t_dlist	*head;

	head = g_msh.envp_lst;
	while (head != NULL)
	{
		head = head->next;
		if (!ft_strncmp(head->content, var, ft_strlen(var)))
			break ;
	}
	return (head->content + ft_strlen(var) + 1);
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
