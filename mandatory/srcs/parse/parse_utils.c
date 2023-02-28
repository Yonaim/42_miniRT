#include "parse_internal.h"

bool	is_color3_in_255(const t_color3 *c)
{
	return (is_vec3_in_range(*c, 0, 255));
}

bool	is_normalized_vec3(const t_vector3 *v)
{
	return (is_vec3_in_range(*v, 0, 1) == true \
		&& is_len_near_one(*v) == true);
}

t_vector3	parse_vector3(const t_token_arr *tokens, int *offset)
{
	t_vector3	v3;

	v3.x = ft_atof(nth_token(tokens, *offset + 1)->str);
	v3.y = ft_atof(nth_token(tokens, *offset + 3)->str);
	v3.z = ft_atof(nth_token(tokens, *offset + 5)->str);
	(*offset) += 7;
	return (v3);
}

double	parse_number(const t_token_arr *tokens, int *offset)
{
	double	n;

	n = ft_atof(nth_token(tokens, *offset)->str);
	(*offset) += 1;
	return (n);
}

t_token	*nth_token(const t_token_arr *tokens, int nth)
{
	t_token *token;

	token = (t_token *)tokens->data[nth];
	return (token);
}
