/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_historry.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:47:35 by zraunio           #+#    #+#             */
/*   Updated: 2021/06/01 14:59:38 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

void	get_history(t_shell *shell)
{
	char	*path;

	path = ft_strnew(PATH_MAX + 1);
	getcwd(path, PATH_MAX);
	path = ft_strjoin_free(path, "/.small_hist", 1);
	shell->hist_path = path;
	shell->hist_fd = 0;
	fetch_history(shell);
}