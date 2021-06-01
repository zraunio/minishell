/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:13:41 by zraunio           #+#    #+#             */
/*   Updated: 2021/06/01 11:26:50 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

char	*get_env(t_shell *shell, char *str)
{
	size_t	i;

	i = 0;
	while (shell->env[i])
	{
		if (ft_strnequ(str, shell->env[i], 3))
			return (ft_strrchr(shell->env[i], '=') + 1);
		i++;
	}
	return (NULL);
}