/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:43:32 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/31 16:49:42 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

int	main(void)
{
	read_keypress();
	return (0);
}

//gcc -Wall -Wextra -Werror srcs/base/*.c -L./libft -lft -o test