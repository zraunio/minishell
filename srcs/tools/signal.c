/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 13:45:59 by zraunio           #+#    #+#             */
/*   Updated: 2021/06/02 17:17:24 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

static t_shell *g_shell;

static void	get_signal(int sig)
{
	sigset_t	set;

	if (sig == SIGINT)
	{
		sigemptyset(&set);
		sigprocmask(SIG_BLOCK, &set, NULL);
		g_shell->n = 0;
		ft_bzero(g_shell->buff, MAX_BUFF);
		ft_putchar('\n');
		prompt(g_shell);
		sigprocmask(SIG_UNBLOCK, &set, NULL);
	}
}

void	set_signal(t_shell *shell)
{
	struct sigaction	sig;

	g_shell = shell;
	sig.sa_handler = get_signal;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sig, NULL);
	sigaction(SIGTSTP, &sig, NULL);
}