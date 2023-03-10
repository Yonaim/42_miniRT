/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_object_line1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:46:12 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/09 03:45:09 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_internal_bonus.h"

/*
	(example):
	pl 0,0,0 0,1.0,0 255,0,225
	sp 0,0,20 20 255,0,0
	cy 50.0,0.0,20.6 0,0,1.0 14.2 21.42 10,0,255
	cn 50.0,0.0,20.6 0,0,1.0 14.2 21.42 10,0,255
	bo 30,0,0 0,20,10 255,255,255

	Solid element의 경우, '<element> <고유 정보> [material] [texture]'
	ex) sp 0,0,20 20 l s 255,0,0
*/
bool	is_point_light_line(const t_token_arr *tokens)
{
	const int	format[] = {
		TOKEN_IDENTIFIER_ELEMENT, TOKEN_PIPE,
		TOKEN_LPAREN,
		TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER,
		TOKEN_RPAREN,
		TOKEN_NUMBER,
		TOKEN_PIPE,
		TOKEN_LPAREN,
		TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER,
		TOKEN_RPAREN,
		TOKEN_NONE
	};

	return (is_valid_formatted_line(IDENTIFIER_ELEMENT_LIGHT, 0, \
									tokens, format));
}

bool	is_plane_line(const t_token_arr *tokens)
{
	const int	format[] = {
		TOKEN_IDENTIFIER_ELEMENT, TOKEN_PIPE,
		TOKEN_LPAREN,
		TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER,
		TOKEN_RPAREN,
		TOKEN_LPAREN,
		TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER,
		TOKEN_RPAREN,
		TOKEN_NONE
	};

	return (is_valid_formatted_line(IDENTIFIER_ELEMENT_PLANE, 1, \
									tokens, format));
}

bool	is_sphere_line(const t_token_arr *tokens)
{
	const int	format[] = {
		TOKEN_IDENTIFIER_ELEMENT, TOKEN_PIPE,
		TOKEN_LPAREN,
		TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER,
		TOKEN_RPAREN,
		TOKEN_NUMBER,
		TOKEN_NONE
	};

	return (is_valid_formatted_line(IDENTIFIER_ELEMENT_SPHERE, 1, \
									tokens, format));
}

bool	is_box_line(const t_token_arr *tokens)
{
	const int	format[] = {
		TOKEN_IDENTIFIER_ELEMENT, TOKEN_PIPE,
		TOKEN_LPAREN,
		TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER,
		TOKEN_RPAREN,
		TOKEN_LPAREN,
		TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER,
		TOKEN_RPAREN,
		TOKEN_NONE
	};

	return (is_valid_formatted_line(IDENTIFIER_ELEMENT_BOX, 1, \
									tokens, format));
}
