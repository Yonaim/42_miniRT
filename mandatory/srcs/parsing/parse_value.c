#include "parsing_internel.h"

int	parse_integer(char **str)
{
	int	n;

	skip_char(str, ' ');
	n = ft_atoi(*str);
	while (**str != ' ' && **str != '\n')
		(*str)++;
	return (n);
}

double	parse_double(char **str)
{
	double	n;

	skip_char(str, ' ');
	n = ft_atof(*str);
	while (**str != ' ' && **str != '\n')
		(*str)++;
	return (n);
}

t_vector3	parse_vector3(char **str)
{
	t_vector3	v;

	skip_char(str, ' ');
	v.x = ft_atof(*str);
	skip_non_char(str, ',');
	(*str)++;
	v.y = ft_atof(*str);
	skip_non_char(str, ',');
	(*str)++;
	v.z = ft_atof(*str);
	while (**str != ' ' && **str != '\n' && **str != '\0')
		(*str)++;
	return (v);
}
