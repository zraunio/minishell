/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:31:03 by zraunio           #+#    #+#             */
/*   Updated: 2021/06/08 14:36:42 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

char	*assign_token(int type, char *str)
{
	char	*token;

	token = (char *)malloc(sizeof(char));
	if (!token)
		return (NULL);
	//type??
	token = str;
	return (token);
}
