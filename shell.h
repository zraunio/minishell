/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 13:36:39 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/31 16:44:26 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "libft/incl/libft.h"
# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <termios.h>
# include <signal.h>
# include <unistd.h>
# include <errno.h>
# include <sys/ioctl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <string.h>
# include <time.h>
# include <curses.h>
# include <dirent.h>
# include <term.h>
# include <fcntl.h>

# define ENTER 13
# define ESC 27
# define DEL 127
# define SPC 32

void	read_keypress(void);

#endif
