/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advance_lexer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:19:21 by zraunio           #+#    #+#             */
/*   Updated: 2021/06/08 14:20:37 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

void	advance_lexer(t_lexer *lex)
{
	if (lex->c != '\0' && lex->n < ft_strlen(lex->contents))
	{
		lex->n++;
		lex->c = lex->contents[lex->n];
	}
}
