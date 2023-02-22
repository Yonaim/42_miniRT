
#include <math.h>
#include <stdbool.h>
#include "vector3.h"

double	len_v3(t_vector3 v)
{
	return (sqrt((v.x * v.x + v.y * v.y + v.z * v.z)));
}

double	len_sqr_v3(t_vector3 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

bool	is_near_zero(t_vector3 v)
{
	const double	epsilon = EPSILON;

	return ((fabs(v.x) < epsilon) \
			&& (fabs(v.y) < epsilon) \
			&& (fabs(v.z) < epsilon));
}
