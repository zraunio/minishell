/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 12:15:01 by zraunio           #+#    #+#             */
/*   Updated: 2021/06/01 13:24:46 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

static char	*set_new_env(char *new, char *env, size_t i)
{
	new = ft_strnew(i);
	ft_memcpy(new, env, i);
	new = ft_strjoin_free(new, &env[i + 1], 1);
	//set environment stuffs
	if (!new)
		return (NULL);
	return (new);
}

void	change_env(t_shell *shell, char *str, char *in)
{
	size_t	i;
	size_t	flg;
	char	*new_env;

	i = 0;
	flg = 0;
	while (shell->env[i])
	{
		if (shell->env[i] && ft_strnequ(str, shell->env[i + 1], 3))
		{
			new_env = set_new_env(new_env, shell->env, i);
			if (!new_env)
				kill_mode(shell->env[i]);
			flg = 1;
			break ;
		}
		i++;
	}
	i = 0;
	if ((ft_strnequ(shell->sh_args[0], "set", 3) == 1) && flg == 0)
	{
		new_env = ft_strjoin(str, "=");
		///set environment stuffs
	}
}