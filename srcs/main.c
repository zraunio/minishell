/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:43:32 by zraunio           #+#    #+#             */
/*   Updated: 2021/06/02 10:59:43 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

int	main(void)
{
	// t_shell	shell;

	// ft_memset(&shell, 0, sizeof(t_shell));
	// rawmode_start();
	srand(time(NULL));
	int i = rand() % 4;
	ft_printf("%d\n", i);
	return (0);
}

//gcc -Wall -Wextra -Werror srcs/base/*.c -L./libft -lft -o test