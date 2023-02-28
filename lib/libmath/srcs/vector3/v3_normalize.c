
#include "vector3.h"

t_vector3	v3_normalize(t_vector3 v)
{
	const double	length = len_v3(v);

	if (length < EPSILON)
		return (vector3(0, 0, 0));
	return (v3_div(v, length));
}
