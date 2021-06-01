/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:26:47 by zraunio           #+#    #+#             */
/*   Updated: 2021/06/01 14:44:14 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

static void	go_home(t_shell *shell)
{
	while (shell->n-- > 0)
		tputs(tgetstr("le", NULL), 1, print_key);
}

void	read_key(t_shell *shell, int c)
{
	if (ft_isprint(c))
		print_key(c);
	else if (c == DEL)
	{
		if (shell->n >= 1)
			return ;//delete whole shell
	}
	else if (c == LFT || c == RGHT || c == UP || c == DWN)
		do_arrows(shell, c);
	else if (c == HOME)
		go_home(shell);
}