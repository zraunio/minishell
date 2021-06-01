/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_arrows.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:46:31 by zraunio           #+#    #+#             */
/*   Updated: 2021/06/01 14:35:54 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

static void	do_left(t_shell *shell)
{
	if (shell->n > 0)
	{
		tputs(tgetstr("le", NULL), 1, print_key);
		shell->n--;
	}
}

static void	do_right(t_shell *shell)
{
	if (shell->n <= (ft_strle(shell->buff) - 1) && shell->buff[shell->n] != 0)
	{
		tputs(tgetstr("nd", NULL), 1, print_key);
		shell->n++;
	}
}

static void	do_up(t_shell *shell)
{
		//check_next
		//point it at next
		tputs(tgetstr("cb", NULL), 1, print_key);
		write(1, "\r", 1);
		ft_memcpy(shell->buff, shell->hist, ft_strlen(shell->hist) + 1);
		//prompt shell
		ft_putstr(shell->buff);
		shell->n = ft_strlen(shell->buff);
}

static void	do_down(t_shell *shell)
{
	if (shell->hist)
	{
		//check_prev
		//point it at prev
		tputs(tgetstr("cb", NULL), 1, print_key);
		write(1, "\r", 1);
		ft_memcpy(shell->buff, shell->hist, ft_strlen(shell->hist) + 1);
		//prompt shell
		ft_putstr(shell->buff);
		shell->n = ft_strlen(shell->buff);
	}
}

void	do_arrows(t_shell *shell, int c)
{
	if (c == LFT)
		do_left(shell);
	else if (c == RGHT)
		do_right(shell);
	else if (c == UP)
		do_up(shell);
	else if (c == DWN)
		do_down(shell);
}