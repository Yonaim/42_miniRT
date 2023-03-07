
#include "vector3.h"

t_vector3	vector3(const double x, const double y, const double z)
{
	t_vector3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_point3	point3(const double x, const double y, const double z)
{
	return ((t_point3)vector3(x, y, z));
}
