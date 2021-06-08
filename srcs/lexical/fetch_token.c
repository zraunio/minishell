/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 11:07:59 by zraunio           #+#    #+#             */
/*   Updated: 2021/06/08 14:38:00 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

char	*fetch_string(t_lexer *lex)
{
	char	*token;
	char	*temp;

	advance_lexer(lex);
	token = (char *)malloc(sizeof(char));
	if (!token)
		return (NULL);
	while (lex->c != '"')
	{
		//realloc &token
		//temp = char as string
		ft_strcat(token, temp);
		advance_lexer(lex);
		free(temp);
	}
	advance_lexer(lex);
	return (); //initialise token (TOKEN STRING, token)
}

char	*fetch_id(t_lexer *lex)
{
	char	*token;
	char	*temp;

	token = (char *)malloc(sizeof(char));
	if (!token)
		return (NULL);
	while (ft_isalnum(lex->c) || lex->c == DASH || lex->c == DOT || lex->c == DOLLAR || lex->c == TILDE) //more??
	{
		//realloc &token
		//temp = char as string
		ft_strcat(token, temp);
		advance_lexer(lex);
		free(temp);
	}
	return (assign_token(TOKEN_ID, token)); //initialise token (TOKEN ID, token)
}

char	*fetch_token(t_lexer *lex)
{
	while (lex->c != '\0' || lex->n < ft_strlen(lex->contents))
	{
		if (lex->c == ' ' || lex->c == ENTER)
		{
			while (lex->c == ' ' || lex->c == 10)
				advance_lexer(lex);
		}
		if (ft_isalnum(lex->c) || lex->c == TILDE || lex->c == DOT || lex->c == DASH || lex->c == DOLLAR) // add more
			fetch_id(lex);
		if (lex->c == '"')
			fetch_string(lex);
		if (lex->c == ';')
			return (advance_with_token(lex, assign_token(TOKEN_SEMI, )));//advance token but (TOKEN_SEMI from token enum), current char as string
	}
	return (assign_token(TOKEN_EOF, "\0"));
}
