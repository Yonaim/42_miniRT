#include "parsing_internel.h"

void	skip_char(char **str, char c)
{
	while (**str == c)
		(*str)++;
}

void	skip_non_char(char **str, char c)
{
	while (**str != c)
		(*str)++;
}

void	skip_until_next_value(char **str)
{
	skip_char(str, ' ');
	skip_non_char(str, ' ');
}

bool	is_num_in_range(double num, double min, double max)
{
	return (min <= num && num <= max);
}

bool	is_vec3_in_range(t_vector3 vec3, double min, double max)
{
	return ((min <= vec3.x && vec3.x <= max)
		&& (min <= vec3.y && vec3.y <= max)
		&& (min <= vec3.z && vec3.z <= max));
}
