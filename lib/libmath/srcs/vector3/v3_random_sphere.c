#include "vector3.h"
#include "random.h"

t_vector3	v3_random_in_unit_sphere(void)
{
	t_vector3	random_point;

	while (1)
	{
		random_point = v3_random(-1, 1);
		if (len_sqr_v3(random_point) >= 1)
			continue ;
		return (random_point);
	}
}

t_vector3	v3_random_on_unit_sphere(void)
{
	return (v3_normalize(v3_random_in_unit_sphere()));
}

t_vector3	v3_random_in_sphere(double radius)
{
	return (v3_mul(v3_random_in_unit_sphere(), radius));
}

t_vector3	v3_random_on_sphere(double radius)
{
	return (v3_mul(v3_random_on_unit_sphere(), radius));
}
