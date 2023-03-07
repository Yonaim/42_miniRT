#include "ray_internal.h"

t_vector3	reflected_vector(t_vector3 in, t_vector3 n)
{
	return (v3_sub(in, v3_mul(n, 2 * v3_dot(in, n))));
}

t_ray	reflected_ray(t_vector3 in_dir, t_hit_record *rec, double fuzz)
{
	const t_vector3	unit_in_dir = v3_normalize(in_dir);
	t_vector3		reflected;

	reflected = reflected_vector(unit_in_dir, rec->normal);
	reflected = v3_add(reflected, v3_mul(v3_random_in_unit_sphere(), fuzz));
	reflected = v3_normalize(reflected);
	return (ray(rec->p, reflected));
}
