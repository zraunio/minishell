/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:04:42 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/31 17:04:57 by zraunio          ###   ########.fr       */
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