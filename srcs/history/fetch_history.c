/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_history.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:58:27 by zraunio           #+#    #+#             */
/*   Updated: 2021/06/02 17:38:01 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

static void	copy_history(t_shell *shell, char *str)
{
	size_t	i;

	i = 0;
	if (!shell->hist)
	{
		shell->hist = (char **)malloc(sizeof(char *) * 2);
		shell->hist[0] = ft_strdup(str);
		shell->hist[1] = NULL;
		shell->n_hist = 2;
		return ;
	}
	else
	{
		while (shell->hist[i] != NULL || i <= shell->n_hist)
			i++;
		if (i == shell->n_hist)
		{
			//realloc hist
			//n_hist == new size
		}
		shell->hist[i] = ft_strdup(str);
		shell->hist[i + 1] = NULL;
	}
	
}

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
			copy_history(shell, line);
	}
	copy_history(shell, ""); //?? maybe no need
}