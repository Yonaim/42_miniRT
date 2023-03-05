
#include "vector3.h"

t_vector3	v3_normalize(t_vector3 v)
{
	if (is_near_zero(v) == true)
		return (vector3(0, 0, 0));
	return (v3_div(v, len_v3(v)));
}
