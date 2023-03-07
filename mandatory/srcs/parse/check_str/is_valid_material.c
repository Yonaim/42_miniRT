#include "../parse_internal.h"
#include <string.h>

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

bool	is_valid_material_default(const t_token_arr *tokens, int offset)
{
	if (tokens->cnt == offset + 8 \
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

bool	is_valid_material_random(const t_token_arr *tokens, int offset)
{
	if (tokens->cnt == offset + 3 \
		&& nth_token(tokens, offset + 1)->type == TOKEN_IDENTIFIER_MATERIAL
		&& ft_strcmp(nth_token(tokens, offset + 1)->str, \
											IDENTIFIER_MATERIAL_RANDOM) == 0)
		return (true);
	else
		return (false);
}

bool	is_valid_material(const t_token_arr *tokens, int offset)
{
	const t_is_valid_material	is_valid_material[] = {
		is_valid_material_default,
		is_valid_material_lambertian,
		is_valid_material_metal,
		is_valid_material_dielectric,
		is_valid_material_emmisive,
		is_valid_material_random,
	};
	int							i;

	if (nth_token(tokens, offset)->type != TOKEN_PIPE)
		return (false);
	i = 0;
	while (i < MATERIAL_TYPE_COUNT)
	{
		if (is_valid_material[i](tokens, offset) == true)
			return (true);
		i++;
	}
	return (false);
}
