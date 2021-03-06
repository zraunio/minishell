/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 17:40:14 by zraunio           #+#    #+#             */
/*   Updated: 2021/06/04 11:07:52 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

static t_lexer	*create_lex(char *buff)
{
	t_lexer	*lex;

	lex = (t_lexer *)malloc(sizeof(t_lexer));
	if (!lex)
		exit (1);
	ft_memset(lex, 0, sizeof(t_lexer));
	lex->contents = buff[lex->n];
	return (lex);
}

void	lexical(t_shell *shell)
{
	t_lexer	*lexer;
	char	*token;

	lexer = create_lex(shell->buff);
	token = fetch_token(lexer);
}
