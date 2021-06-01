/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_keypress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 13:41:40 by zraunio           #+#    #+#             */
/*   Updated: 2021/06/01 13:48:52 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

char	ctrl_key(int key)
{
	return (key & 0x1f);
}

int	set_key(void)
{
	int		n;
	char	c;

	n = 0;
	while (n != 1)
	{
		n = read(STDIN_FILENO, &c, 1);
		if (n == -1 && errno != EAGAIN)
			kill_mode("read");
		if (ctrl_key('c') == c)
		{
			write (STDOUT_FILENO, "\x1b[2J", 4);
			write (STDOUT_FILENO, "\x1b[H", 3);
			exit (0);
		}
	}
	return (c);
}

void	read_keypress(void)
{
	int c;
	
	rawmode_start();
	while (1)
	{
		refresh_screen();
		c = set_key();
		if (c == ENTER)
			ft_putendl("");
		else
			ft_putchar(c);
	}
}