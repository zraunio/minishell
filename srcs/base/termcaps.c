/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:08:55 by zraunio           #+#    #+#             */
/*   Updated: 2021/06/02 13:24:49 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

void	termcaps(t_shell *shell)
{
	char	*s;
	char	*buff[3000];
	int		i;

	s = get_env(shell, "TERM");
	if (s == NULL)
		ft_putendl_fd("please specify a terminal type", STDERR_FILENO);
	i = tgetent(buff, s);
	if (i > 0)
	{
		tputs(tgetstr("cl", NULL), 1, print_key);
		return ;
	}
	else if (i < 0)
		ft_putendl_fd("could not access termcap database", STDERR_FILENO);
	else if (i == 0)
		ft_putendl_fd("terminal type not defined", STDERR_FILENO);
	exit (1);
}
