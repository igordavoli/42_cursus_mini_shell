/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 01:59:00 by idavoli-          #+#    #+#             */
/*   Updated: 2022/05/29 03:25:10 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

char	*ft_getenv(char *var)
{
	t_dlist	*head;
	char	*ret;

	head = g_msh.envp_lst;
	while (head != NULL)
	{
		head = head->next;
		if (!ft_strncmp(head->content, var, ft_strlen(var)))
			break ;
	}
	ret = ft_substr(head->content, ft_strlen(var) + 1, ft_strlen(head->content));
	return (ret);
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
