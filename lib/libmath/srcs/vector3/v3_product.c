
#include "vector3.h"

double	v3_dot(t_vector3 u, t_vector3 v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

t_vector3	v3_cross(t_vector3 u, t_vector3 v)
{
	return (vector3(u.y * v.z - u.z * v.y, \
				u.z * v.x - u.x * v.z, \
				u.x * v.y - u.y * v.x));
}

t_vector3	v3_comp_wise(t_vector3 u, t_vector3 v)
{
	return (vector3(u.x * v.x, u.y * v.y, u.z * v.z));
}
