/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rawmode_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:05:57 by zraunio           #+#    #+#             */
/*   Updated: 2021/06/01 11:06:09 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

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