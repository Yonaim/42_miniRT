
#include "object_internal.h"

/**
 * @brief 
 * Calculates the probability density function for sampling a point 
 * on the surface of a sphere 
 * @param self Pointer to the sphere object
 * @param origin Origin of the ray
 * @param dir Direction of the ray
 * @return Probability density function value
 */
double	calculate_sphere_sampling_pdf(\
		t_object *self, const t_vector3 *origin, const t_vector3 *dir)
{
	const t_object_sphere	*sp = (t_object_sphere *)self;
	const t_ray				sphere_ray = ray(*origin, *dir);
	t_hit_record			h_rec;
	double					max_cosine;
	double					solid_angle;

	if (sp->hit(self, (t_ray *)&sphere_ray, &h_rec, T_INFINITY) == false)
		return (0);
	max_cosine = sqrt(1 - pow(sp->radius, 2) \
						/ len_sqr_v3(v3_sub(sp->center, *origin)));
	solid_angle = 2 * M_PI * (1 - max_cosine);
	return (1 / solid_angle);
}

/**
 * @brief
 * Generates a random direction from a point towards the surface of a sphere
 * @param random_dir Pointer to the output random direction vector
 * @param radius Radius of the sphere
 * @param dist_sqr Distance squared between the point and the sphere center
 */
static void	generate_random_direction_to_sphere(
			t_vector3 *random_dir, const double radius, const double dist_sqr)
{
	const double	azimuthal_angle = 2 * M_PI * random_double();
	const double	cos_polar_angle = 1 - random_double() \
									* (1 - sqrt(1 - pow(radius, 2) / dist_sqr));
	const double	sin_polar_angle = sqrt(1 - pow(cos_polar_angle, 2));

	(*random_dir).x = cos(azimuthal_angle) * sin_polar_angle;
	(*random_dir).y = sin(azimuthal_angle) * sin_polar_angle;
	(*random_dir).z = cos_polar_angle;
}

/**
 * @brief 
 * Generates a random direction vector pointing towards the surface of a sphere
 * @param self Pointer to the sphere object
 * @param origin Origin of the ray
 * @return Random direction vector
 */
t_vector3	get_random_vector_to_sphere(
			const t_object *self, const t_point3 *origin)
{
	const t_object_sphere	*sp = (t_object_sphere *)self;
	const t_vector3			dir = v3_sub(sp->center, *origin);
	t_onb					onb;
	t_vector3				random;

	build_onb_from_w(&onb, &dir);
	generate_random_direction_to_sphere(&random, sp->radius, len_sqr_v3(dir));
	transform_to_onb_in_place(&onb, &random);
	return (random);
}
