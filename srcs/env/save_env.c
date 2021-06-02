/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 13:32:08 by zraunio           #+#    #+#             */
/*   Updated: 2021/06/02 13:45:20 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

void	save_env(t_shell *shell, char **env)
{
	size_t	i;

	i = 0;
	while (env[i++])
	{
		shell->env[i] = ft_strdup(env[i]);
		if (!shell->env[i])
		{
			ft_arr_free(shell->env);
			exit (EXIT_FAILURE);
		}
	}
}