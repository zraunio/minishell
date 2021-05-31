/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 13:41:40 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/31 16:51:24 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

void kill_mode(const char *str)
{
	write (STDOUT_FILENO, "\x1b[2J", 4);
	write (STDOUT_FILENO, "\x1b[H", 3);
	perror(str);
	exit(1);
}

void	rawmode_start(void)
{
	struct termios raw;

	if (tcgetattr(0, &raw) == -1)
		kill_mode("tcgetattr");
	raw.c_lflag &= ~(ECHO | IEXTEN | ICANON | ISIG);
	raw.c_iflag &= ~(ICRNL | IXON);
	raw.c_oflag &= ~(OPOST);
	if (tcsetattr(0, TCSANOW, &raw) == -1)
		kill_mode("tcsetattr");
}

char	ctrl_key(int key)
{
	return (key & 0x1f);
}

int	read_key(void)
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
	
	c = read_key();
	if (c == ENTER)
	{
		ft_putendl("");
		return ;
	}
	else
		ft_putchar(c);
}