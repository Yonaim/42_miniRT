
#include "vector3.h"

t_vector3	v3_add(const t_vector3 u, const t_vector3 v)
{
	return (vector3(u.x + v.x, u.y + v.y, u.z + v.z));
}

t_vector3	v3_sub(const t_vector3 u, const t_vector3 v)
{
	return (vector3(u.x - v.x, u.y - v.y, u.z - v.z));
}

t_vector3	v3_mul(const t_vector3 v, const double t)
{
	return (vector3(t * v.x, t * v.y, t * v.z));
}

t_vector3	v3_div(const t_vector3 v, const double t)
{
	return (vector3(v.x / t, v.y / t, v.z / t));
}
