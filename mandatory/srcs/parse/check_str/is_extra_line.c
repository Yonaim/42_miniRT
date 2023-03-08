/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_extra_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:46:12 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/07 22:13:13 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_internal.h"

/*
	(example):
	A 0.2 255,255,255
	C -50,0,20 0,0,0 70
	L -40,0,30 0.7 255,255,255
*/

bool	is_ambient_line(const t_token_arr *tokens)
{
	const int	format[] = {
		TOKEN_IDENTIFIER_ELEMENT, TOKEN_PIPE,
		TOKEN_NUMBER,
		TOKEN_LPAREN,
		TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER,
		TOKEN_RPAREN,
		TOKEN_NONE
	};

	return (is_valid_formatted_line(IDENTIFIER_ELEMENT_AMBIENT, 0, \
									tokens, format) == true);
}

bool	is_camera_line(const t_token_arr *tokens)
{
	const int	format[] = {
		TOKEN_IDENTIFIER_ELEMENT, TOKEN_PIPE,
		TOKEN_LPAREN,
		TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER,
		TOKEN_RPAREN,
		TOKEN_LPAREN,
		TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER,
		TOKEN_RPAREN,
		TOKEN_NUMBER,
		TOKEN_NONE
	};

	return (is_valid_formatted_line(IDENTIFIER_ELEMENT_CAMERA, 0, \
									tokens, format));
}
