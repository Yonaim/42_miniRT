#include <stdbool.h>
#include "vector3.h"

bool	is_num_in_range(double n, double min, double max)
{
	return (min <= n && n <= max);
}

bool	is_vec3_in_range(t_vector3 v, double min, double max)
{
	return ((min <= v.x && v.x <= max) \
			&& (min <= v.y && v.y <= max) \
			&& (min <= v.z && v.z <= max));
}

double	clamp(double x, double min, double max)
{
	if (x < min)
		return (min);
	if (x > max)
		return (max);
	return (x);
}
