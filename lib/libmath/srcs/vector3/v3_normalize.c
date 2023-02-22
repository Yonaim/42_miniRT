
#include "vector3.h"

t_vector3	v3_normalize(t_vector3 v)
{
	return (v3_div(v, len_v3(v)));
}
