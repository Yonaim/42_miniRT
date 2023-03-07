#include "ray_internal.h"

static double	reflectance(double cosine, double idx_ratio)
{
	double	r0;

	r0 = (1 - idx_ratio) / (1 + idx_ratio);
	r0 *= r0;
	return (r0 + (1 - r0) * pow(1 - cosine, 5));
}

t_vector3	refracted_vector(t_vector3 in, t_vector3 n, double idx_ratio)
{
	const double	cos_in = fmin(-v3_dot(in, n), 1);
	const double	sin_in = sqrt(1 - cos_in * cos_in);
	t_vector3		refracted_perp;
	t_vector3		refracted_par;
	t_vector3		refracted;

	if (idx_ratio * sin_in > 1
		|| reflectance(cos_in, idx_ratio) > random_double())
		return (reflected_vector(in, n));
	refracted_perp = v3_mul(v3_add(in, v3_mul(n, cos_in)), idx_ratio);
	refracted_par = v3_mul(n, -sqrt(fabs(1 - len_sqr_v3(refracted_perp))));
	refracted = v3_add(refracted_par, refracted_perp);
	return (refracted);
}

t_ray	refracted_ray(t_vector3 in_dir, t_hit_record *rec, double idx_ratio)
{
	const t_vector3	unit_in_dir = v3_normalize(in_dir);
	t_vector3		refracted;

	refracted = refracted_vector(unit_in_dir, rec->normal, idx_ratio);
	refracted = v3_normalize(refracted);
	return (ray(rec->p, refracted));
}

