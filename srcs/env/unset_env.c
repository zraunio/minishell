/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 12:23:14 by zraunio           #+#    #+#             */
/*   Updated: 2021/06/01 15:25:59 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

void	unset_env(t_shell *shell)
{
	size_t	i;

	i = 0;
	while (shell->sh_args[i])
		i++;
	if (i != 2)
		ft_putendl("del_env: invalid arguments");
	else
	{
		i = 0;
		while (shell->env[i])
		{
			if (shell->env[i] && ft_strnequ(shell->sh_args[1], shell->env[i + 1], \
			3))
				///delete environment
			i++;
		}
	}
}