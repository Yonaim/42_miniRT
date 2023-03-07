#include "object_internal.h"

double	disk_sampling_pdf_value(
		t_object_disk *di, t_hit_record *h_rec, t_vector3 *dir)
{
	const double	area = M_PI * pow(di->radius, 2);
	const double	cosine = fabs(v3_dot(*dir, h_rec->normal)) / len_v3(*dir);
	const double	dst_sqr = pow(h_rec->t, 2) * len_sqr_v3(*dir);

	return (dst_sqr / (area * cosine));
}

/**
 * @brief 
 * Calculates the probability density function for sampling a point 
 * on the surface of a disk 
 * @param self Pointer to the disk object
 * @param origin Origin of the ray
 * @param dir Direction of the ray
 * @return Probability density function value
 */
double	calculate_disk_sampling_pdf(
		t_object *self, const t_vector3 *origin, const t_vector3 *dir)
{
	const t_object_disk	*di = (t_object_disk *)self;
	const t_ray			di_ray = ray(*origin, *dir);
	t_hit_record		h_rec;
	double				area;
	double				cosine;

	if (di->hit(self, (t_ray *)&di_ray, &h_rec, T_INFINITY) == false)
		return (0);
	return (disk_sampling_pdf_value(di, &h_rec, dir));
}

/**
 * @brief
 * Generates a random direction from a point towards the surface of a disk
 * @param random_dir Pointer to the output random direction vector
 * @param radius Radius of the disk
 * @param dist_sqr Distance squared between the point and the disk center
 */
static void	generate_random_direction_to_disk(
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
 * Generates a random direction vector pointing towards the surface of a disk
 * @param self Pointer to the disk object
 * @param origin Origin of the ray
 * @return Random direction vector
 */
t_vector3	get_random_vector_to_disk(
			const t_object *self, const t_point3 *origin)
{
	const t_object_disk	*di = (t_object_disk *)self;
	t_onb				onb;
	const t_vector3		random = v3_random_in_disk(di->radius);
	const t_vector3		dir = v3_add(v3_sub(di->center, *origin), random);
	t_vector3			random;

	build_onb_from_w(&onb, &di->normal);
	
	build_onb_from_w(&onb, &dir);
	generate_random_direction_to_disk(&random, di->radius, len_sqr_v3(dir));
	transform_to_onb_in_place(&onb, &random);
	return (random);
}
