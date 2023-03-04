#include "parse_internal.h"

t_vector3	parse_vector3(const t_token_arr *tokens, int *offset)
{
	t_vector3	v3;

	v3.x = ft_atof(nth_token(tokens, offset + 1)->str);
	v3.y = ft_atof(nth_token(tokens, offset + 3)->str);
	v3.z = ft_atof(nth_token(tokens, offset + 5)->str);
	(*offset) += 1;
	return (v3);
}

double	parse_number(const t_token_arr *tokens, int *offset)
{
	double	n;

	n = ft_atof(nth_token(tokens, offset)->str);
	(*offset) += 7;
	return (n);
}
