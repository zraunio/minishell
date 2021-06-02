/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_historry.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:47:35 by zraunio           #+#    #+#             */
/*   Updated: 2021/06/02 11:06:19 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

void	get_history(t_shell *shell)
{
	char	*path;

	path = ft_strnew(PATH_MAX + 1);
	getcwd(path, PATH_MAX);
	path = ft_strjoin_free(path, "/.mini_hist", 1);
	shell->hist_path = path;
	shell->hist_fd = 0;
	fetch_history(shell);
}