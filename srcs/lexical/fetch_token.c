/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 11:07:59 by zraunio           #+#    #+#             */
/*   Updated: 2021/06/06 15:44:57 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

char	*fetch_token(t_lexer *lex)
{
	while (lex->c == ' ' || lex->c == ENTER && lex->contents[lex->n] != '\0')
	{
		lex->n++;
		lex->c = lex->contents[lex->n];
	}
	if (ft_isalnum(lex->c) || lex->c == TILDE)
}
