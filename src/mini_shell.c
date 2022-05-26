/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:26:38 by idavoli-          #+#    #+#             */
/*   Updated: 2022/05/25 23:01:10 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	main(int argc, char **argv, char **envp)
{
	t_msh	msh;

	msh.argc = argc;
	msh.argv = argv;
	msh.env = envp;
	while (1)
	{
		msh.line = readline("idavoli- in 42> ");
		if (*msh.line)
		{
			add_history(msh.line);
			msh.splitted_line = ft_split2(msh.line, ' ');
			execute(msh.splitted_line);
			free(msh.line);
			ft_free_ptrs((void **)msh.splitted_line);
		}
	}
	return (0);
}
