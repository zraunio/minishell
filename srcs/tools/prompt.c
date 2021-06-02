/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 14:36:33 by zraunio           #+#    #+#             */
/*   Updated: 2021/06/02 17:15:32 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

static void	prompt_date(void)
{
	time_t	today;
	char	host[BUFF_SIZE];

	today = time(NULL);
	gethostname(host, BUFF_SIZE);
	*ft_strchr(host, '.') = '\0';
	ft_printf("%.2s-%.3s-%.2s %.5s%s:", ctime(&today) + 8, ctime(&today) + 4,\
ctime(&today) + 22, ctime(&today) + 11, host);
}

void	prompt(t_shell *shell)
{
	char	*pwd;
	char	*user;
	char	*home;
	size_t	i;

	i = 0;
	prompt_date();
	while (shell->env[i++])
	{
		if (ft_strnequ("PWD", shell->env[i], 3))
			pwd = (ft_strrchr(shell->env[i], '=') + 1);
		if (ft_strnequ("LOGNAME", shell->env[i], 7))
			user = (ft_strrchr(shell->env[i], '=') + 1);
		if (ft_strnequ("HOME", shell->env[i], 4))
			home = (ft_strrchr(shell->env[i], '=') + 1);
	}
	if (ft_strstr(pwd, home))
	{
		pwd = ft_strsub(pwd, ft_strle(home), (ft_strlen(pwd) - ft_strlen(home)));
		print_fd(STDERR_FILENO, "~%s.%s%%", pwd, user);
		free(pwd);
		return ;
	}
	print_fd(STDERR_FILENO, "%s %s", pwd, user);
	ft_putstr_fd("%% ", STDERR_FILENO);
}