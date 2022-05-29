/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 02:10:00 by idavoli-          #+#    #+#             */
/*   Updated: 2022/05/29 02:40:01 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

int	export(char *var)
{
	t_list	*new_var;
	char	*mall_var;

	if (*var == '=')
		return (1);
	mall_var = ft_strdup(var);
	if (mall_var == NULL)
		return (1);
	new_var = ft_lstnew((void *)mall_var);
	if (new_var == NULL)
		return (1);
	ft_lstadd_back(&g_msh.envp_lst, new_var);
	return (0);
}
