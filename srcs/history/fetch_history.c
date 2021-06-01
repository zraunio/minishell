/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_history.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:58:27 by zraunio           #+#    #+#             */
/*   Updated: 2021/06/01 15:09:25 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

static int	file_isempty(char *path)
{
	struct stat	buff;

	if (stat(path, &buff))
		return (1);
	if (buff.st_size <= 1)
		return (1);
	return (0);
	
}

void	fetch_history(t_shell *shell)
{
	char	*line;

	shell->hist = NULL;
	shell->hist_fd = open(shell->hist_path, O_RDWR | O_APPEND | O_CREAT, 0666);
	if (shell->hist_fd == -1)
		return ;
	if (!file_isempty(shell->hist_path))
	{
		while (get_next_line(shell->hist_fd, &line) > 0)
			//new history
	}
	//new history
}