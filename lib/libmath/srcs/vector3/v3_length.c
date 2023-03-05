
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
	const double	epsilon = EPSILON; // 굳이 지역변수로 뺀 이유가 있나?

	return ((fabs(v.x) < epsilon) \
			&& (fabs(v.y) < epsilon) \
			&& (fabs(v.z) < epsilon));
}

bool	is_len_near_one(t_vector3 v)
{
	const double	len = len_v3(v);

	return (1 - EPSILON <= len && len <= 1 + EPSILON);
}
