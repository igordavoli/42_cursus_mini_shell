/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 04:26:33 by idavoli-          #+#    #+#             */
/*   Updated: 2022/05/30 21:48:48 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

char	*refresh_prompt(void)
{
	char	*prompt;
	char	cwd[PATH_MAX];

	if (g_msh.prompt)
		free(g_msh.prompt);
	prompt = "user on domain in ";
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		prompt = ft_strjoin2(prompt, cwd, 0, 0);
	g_msh.prompt = ft_strjoin2(prompt, "> ", 1, 0);
	return (g_msh.prompt);
}
