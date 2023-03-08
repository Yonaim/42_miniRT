#include "../parse_internal.h"

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
