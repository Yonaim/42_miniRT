/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_material2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 03:40:02 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/09 03:43:22 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_internal.h"

bool	is_valid_material_lambertian(const t_token_arr *tokens, int offset)
{
	if (tokens->cnt == offset + 10 \
		&& (ft_strcmp(nth_token(tokens, ++offset)->str, \
										IDENTIFIER_MATERIAL_LAMBERTIAL) == 0)
		&& nth_token(tokens, offset)->type == TOKEN_IDENTIFIER_MATERIAL \
		&& nth_token(tokens, ++offset)->type == TOKEN_IDENTIFIER_TEXTURE
		&& nth_token(tokens, ++offset)->type == TOKEN_LPAREN
		&& nth_token(tokens, ++offset)->type == TOKEN_NUMBER
		&& nth_token(tokens, ++offset)->type == TOKEN_COMMA
		&& nth_token(tokens, ++offset)->type == TOKEN_NUMBER
		&& nth_token(tokens, ++offset)->type == TOKEN_COMMA
		&& nth_token(tokens, ++offset)->type == TOKEN_NUMBER
		&& nth_token(tokens, ++offset)->type == TOKEN_RPAREN)
		return (true);
	else
		return (false);
}

bool	is_valid_material_metal(const t_token_arr *tokens, int offset)
{
	if (tokens->cnt == offset + 11 \
		&& (ft_strcmp(nth_token(tokens, ++offset)->str, \
										IDENTIFIER_MATERIAL_METAL) == 0)
		&& nth_token(tokens, offset)->type == TOKEN_IDENTIFIER_MATERIAL \
		&& nth_token(tokens, ++offset)->type == TOKEN_NUMBER
		&& nth_token(tokens, ++offset)->type == TOKEN_IDENTIFIER_TEXTURE
		&& nth_token(tokens, ++offset)->type == TOKEN_LPAREN
		&& nth_token(tokens, ++offset)->type == TOKEN_NUMBER
		&& nth_token(tokens, ++offset)->type == TOKEN_COMMA
		&& nth_token(tokens, ++offset)->type == TOKEN_NUMBER
		&& nth_token(tokens, ++offset)->type == TOKEN_COMMA
		&& nth_token(tokens, ++offset)->type == TOKEN_NUMBER
		&& nth_token(tokens, ++offset)->type == TOKEN_RPAREN)
		return (true);
	else
		return (false);
}

bool	is_valid_material_dielectric(const t_token_arr *tokens, int offset)
{
	if (tokens->cnt == offset + 9 \
		&& (ft_strcmp(nth_token(tokens, ++offset)->str, \
										IDENTIFIER_MATERIAL_DIELECTRIC) == 0)
		&& nth_token(tokens, offset)->type == TOKEN_IDENTIFIER_MATERIAL \
		&& nth_token(tokens, ++offset)->type == TOKEN_LPAREN \
		&& nth_token(tokens, ++offset)->type == TOKEN_NUMBER
		&& nth_token(tokens, ++offset)->type == TOKEN_COMMA
		&& nth_token(tokens, ++offset)->type == TOKEN_NUMBER
		&& nth_token(tokens, ++offset)->type == TOKEN_COMMA
		&& nth_token(tokens, ++offset)->type == TOKEN_NUMBER
		&& nth_token(tokens, ++offset)->type == TOKEN_RPAREN)
		return (true);
	else
		return (false);
}

bool	is_valid_material_emmisive(const t_token_arr *tokens, int offset)
{
	if (tokens->cnt == offset + 10 \
		&& (ft_strcmp(nth_token(tokens, ++offset)->str, \
										IDENTIFIER_MATERIAL_EMMISIVE) == 0)
		&& nth_token(tokens, offset)->type == TOKEN_IDENTIFIER_MATERIAL \
		&& nth_token(tokens, ++offset)->type == TOKEN_IDENTIFIER_TEXTURE
		&& nth_token(tokens, ++offset)->type == TOKEN_LPAREN
		&& nth_token(tokens, ++offset)->type == TOKEN_NUMBER
		&& nth_token(tokens, ++offset)->type == TOKEN_COMMA
		&& nth_token(tokens, ++offset)->type == TOKEN_NUMBER
		&& nth_token(tokens, ++offset)->type == TOKEN_COMMA
		&& nth_token(tokens, ++offset)->type == TOKEN_NUMBER
		&& nth_token(tokens, ++offset)->type == TOKEN_RPAREN)
		return (true);
	else
		return (false);
}
