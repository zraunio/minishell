/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 13:36:39 by zraunio           #+#    #+#             */
/*   Updated: 2021/06/08 14:36:48 by zraunio          ###   ########.fr       */
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

# define TOKEN_ID 0x1
# define TOKEN_EQUALS 0x2
# define TOKEN_STRING 0x4
# define TOKEN_SEMI 0x8
# define TOKEN_COMMA 0x10
# define TOKEN_EOF 0x20

typedef struct	s_lexer
{
	char	c;
	size_t	n;
	char	*contents;
}				t_lexer;

typedef struct s_shell
{
	char	**env;
	char	**tok;
	char	**hist;
	char	*tok;
	t_lexer	*lex;
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
/* -----LEXER TOOLS----- */
void	lexical(t_shell *shell);
char	*fetch_token(t_lexer *lex);
void	advance_lexer(t_lexer *lex);
char	*advance_with_token(t_lexer *lex, char *token);
char	*assign_token(int type, char *str);
#endif
