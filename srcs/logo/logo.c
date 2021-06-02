/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:29:23 by zraunio           #+#    #+#             */
/*   Updated: 2021/06/02 15:02:47 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

static void	logo3(void)
{
	ft_putendl("                   o8o               o8o           oooo       \
           oooo  oooo");
	ft_putendl("                   `\"'               `\"'           `888        \
          `888  `888");
	ft_putendl("ooo. .oo.  .oo.   oooo  ooo. .oo.   oooo   .oooo.o  888 .oo.   \
 .ooooo.   888   888");
	ft_putendl("`888P\"Y88bP\"Y88b  `888  `888P\"Y88b  `888  d88(  \"8  888P\"Y88b  \
d88' `88b  888   888");
	ft_putendl(" 888   888   888   888   888   888   888  `\"Y88b.   888   888  \
888ooo888  888   888");
	ft_putendl(" 888   888   888   888   888   888   888  o.  )88b  888   888  \
888    .o  888   888");
	ft_putendl("o888o o888o o888o o888o o888o o888o o888o 8\"\"888P' o888o o888o \
`Y8bod8P' o888o o888o");
	ft_putendl("");
	ft_putendl("									~ zraunio");
}

static void	logo2(void)
{
	ft_putendl("                           .        . . ");
	ft_putendl("          o         o      |        | | ");
	ft_putendl(".--.--.   .  .--.   .  .--.|--. .-. | | ");
	ft_putendl("|  |  |   |  |  |   |  `--.|  |(.-' | | ");
	ft_putendl("'  '  `--' `-'  `--' `-`--''  `-`--'`-`-");
	ft_putendl("");
	ft_putendl("                              ~ zraunio");
}

static void	logo1(void)
{
	ft_putendl(" ____        _____       ____        ______");
	ft_putendl("/\\  _`\\     /\\  __`\\    /\\  _`\\     /\\__  _\\");
	ft_putendl("\\ \\ \\L\\ \\   \\ \\ \\/\\ \\   \\ \\ \\L\\ \\   \\/_/\\ \\/");
	ft_putendl(" \\ \\ ,  /    \\ \\ \\ \\ \\   \\ \\ ,  /      \\ \\ \\");
	ft_putendl("  \\ \\ \\ \\     \\ \\ \\_\\ \\   \\ \\ \\ \\       \\_\\ \\__ ");
	ft_putendl("   \\ \\_\\ \\_\\   \\ \\_____\\   \\ \\_\\ \\_\\    /\\_____\\");
	 ft_putendl("    \\/_/\\/ /    \\/_____/    \\/_/\\/ /    \\/_____/");
	ft_putchar('\n');
	ft_putendl("				~ minishell project");
}

void	set_logo(t_shell *shell)
{
	srand(time(NULL));
	shell->logo = rand() % 4;
	if (shell->logo == 0)
		return ;
	if (shell->logo == 1)
		logo1();
	else if (shell->logo == 2)
		logo2();
	else if (shell->logo == 3)
		logo3();
}

