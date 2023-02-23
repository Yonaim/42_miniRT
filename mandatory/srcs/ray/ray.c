#include "ray_internal.h"

t_ray	ray(t_point3 origin, t_vector3 dir)
{
	t_ray	ray;

	ray.origin = origin;
	ray.dir = dir;
	return (ray);
}

t_point3	ray_at(t_ray *ray, double t)
{
	return ((t_point3)v3_add(ray->origin, v3_mul(ray->dir, t)));
}
