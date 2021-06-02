/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 13:36:39 by zraunio           #+#    #+#             */
/*   Updated: 2021/06/02 17:32:45 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "libft/incl/libft.h"
# include "keys.h"
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
# include <limits.h>

# define H_SIZE 2900
# define MAX_BUFF 4096

typedef struct s_shell
{
	char	**env;
	char	**tok;
	char	**hist;
	size_t	n_hist;
	char	*hist_path;
	int		hist_fd;
	char	**hash_str;
	char	*hash_one[H_SIZE];
	char	buff[MAX_BUFF];
	char	**args;
	char	**sh_args;
	int		n;
	int		logo;
}				t_shell;

/* -----KEYS----- */
int		print_key(int c);
void	read_keypress(void);
void	read_key(t_shell *shell, int c);
void	do_arrows(t_shell *shell, int c);
/* -----LINE-EDIT----- */
void	rawmode_start(void);
void	kill_mode(const char *str);
void	termcaps(t_shell *shell);
/* -----ENVIRONMENT----- */
char	*get_env(t_shell *shell, char *str);
void	change_env(t_shell *shell, char *str, char *in);
void	unset_env(char **env);
void	save_env(t_shell *shell, char **env);
/* -----HISTORY----- */
void	fetch_history(t_shell *shell);
void	get_history(t_shell *shell);
/* -----SETUP TOOLS----- */
void	set_signal(t_shell *shell);
void	prompt(t_shell *shell);

#endif
