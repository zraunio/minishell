/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advance_with_token.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:27:08 by zraunio           #+#    #+#             */
/*   Updated: 2021/06/08 14:28:53 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

char	*advance_with_token(t_lexer *lex, char *token)
{
	advance_lexer(lex);
	return(token);
}
