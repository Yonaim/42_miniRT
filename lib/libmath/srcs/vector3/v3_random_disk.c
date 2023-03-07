#include "vector3.h"
#include "random.h"

t_vector3	v3_random_in_unit_disk(void)
{
	t_vector3	random;

	while (1)
	{
		random = vector3(\
			random_double_range(-1, 1), random_double_range(-1, 1), 0);
		if (len_sqr_v3(random) >= 1)
			continue ;
		return (random);
	}
}

t_vector3	v3_random_on_unit_disk(void)
{
	return (v3_normalize(v3_random_in_unit_disk()));
}

t_vector3	v3_random_in_disk(double radius)
{
	return (v3_mul(v3_random_in_unit_disk(), radius));
}

t_vector3	v3_random_on_disk(double radius)
{
	return (v3_mul(v3_random_on_unit_disk(), radius));
}
