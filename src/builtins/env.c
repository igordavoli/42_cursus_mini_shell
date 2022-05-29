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

static void	print(void *varenv)
{
	printf("%s\n", (char *)varenv);
}

int	env(void)
{
	ft_dlstiter(g_msh.envp_lst, &print);
	return (0);
}
