/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:12:23 by zraunio           #+#    #+#             */
/*   Updated: 2021/06/01 15:20:35 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

static void	set_one_env(t_shell *shell)
{
	size_t	i;

	i = 0;
	while (shell->env[i])
		ft_putendl(shell->env[i++]);
}

void	set_env(t_shell *shell)
{
	size_t	i;

	i = 0;
	while (shell->sh_args[i])
		i++;
	if (i = 1)
		set_one_env(shell);
	else if (i > 3)
		ft_printf("string not in pwd: %s\n", shell->sh_args[1]);
	else if (i == 2)
		change_env(shell, shell->sh_args[1], shell->sh_args[2]);
	else if (i == 3)
		change_env(shell, shell->sh_args[1], "");
	else
		ft_printf("no such file or directory: %s\n", shell->sh_args[1]);
}