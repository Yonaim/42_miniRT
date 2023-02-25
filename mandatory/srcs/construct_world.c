#include <stddef.h>
#include "libmath.h"
#include "material.h"
#include "object.h"
#include "world.h"
#include "typedef.h"

static t_error	add_ground_object(t_world *world);
static t_error	add_small_spheres(t_world *world);
static t_error	add_big_spheres(t_world *world);

t_error	construct_world(t_world *world)
{
	if (add_ground_object(world) == ERROR)
		return (ERROR);
	if (add_small_spheres(world) == ERROR)
		return (ERROR);
	if (add_big_spheres(world) == ERROR)
		return (ERROR);
	return (ERROR_NONE);
}

static t_error	add_ground_object(t_world *world)
{
	t_material	*ground_material;
	t_object	*ground;

	ground_material = new_lambertian(GROUND_ALBEDO);
	if (ground_material == NULL)
		return (ERROR);
	ground = new_sphere(point3(0, -1000, 0), 1000, ground_material);
	if (ground == NULL)
		return (ERROR);
	if (add_object(world, ground) == ERROR)
		return (ERROR);
	return (ERROR_NONE);
}

static t_error	_add_lambertian_sp(t_world *world, t_point3 center)
{
	t_color3	albedo;
	t_material	*material;
	t_object	*sp;

	albedo = v3_comp_wise(v3_random(0, 1), v3_random(0, 1));
	material = new_lambertian(albedo);
	if (material == NULL)
		return (ERROR);
	sp = new_sphere(center, 0.2, material);
	if (sp == NULL)
		return (ERROR);
	if (add_object(world, sp) == ERROR)
		return (ERROR);
	return (ERROR_NONE);
}

static t_error	_add_metal_sp(t_world *world, t_point3 center)
{
	t_color3	albedo;
	double		fuzz;
	t_material	*material;
	t_object	*sp;

	albedo = v3_random(0.5, 1);
	fuzz = random_double_range(0, 0.5);
	material = new_metal(albedo, fuzz);
	if (material == NULL)
		return (ERROR);
	sp = new_sphere(center, 0.2, material);
	if (sp == NULL)
		return (ERROR);
	if (add_object(world, sp) == ERROR)
		return (ERROR);
	return (ERROR_NONE);
}
static t_error	_add_dielectric_sp(t_world *world, t_point3 center)
{
	t_material	*material;
	t_object	*sp;

	material = new_dielectric(1.5);
	if (material == NULL)
		return (ERROR);
	sp = new_sphere(center, 0.2, material);
	if (sp == NULL)
		return (ERROR);
	if (add_object(world, sp) == ERROR)
		return (ERROR);
	return (ERROR_NONE);
}

static t_error	add_small_spheres(t_world *world)
{
	int			i;
	int			j;
	double		rullet;
	t_point3	center;

	i = -5;
	while (i < 5)
	{
		j = -5;
		while (j < 5)
		{
			rullet = random_double();
			center = point3(i + 0.9 * random_double(), \
							0.2, \
							j + 0.9 * random_double());
			if (len_v3(v3_sub(center, point3(4, 0.2, 0))) > 0.9)
			{
				if (rullet < 0.8)
				{
					if (_add_lambertian_sp(world, center) == ERROR)
						return (ERROR);
				}
				else if (rullet < 0.95)
				{
					if (_add_metal_sp(world, center) == ERROR)
						return (ERROR);
				}
				else if (_add_dielectric_sp(world, center) == ERROR)
					return (ERROR);
			}
			j++;
		}
		i++;
	}
	return (ERROR_NONE);
}

static t_error	add_big_spheres(t_world *world)
{
	t_material	*m;
	t_object	*sp;

	if ((m = new_dielectric(1.5)) == NULL)
		return (ERROR);
	if ((sp = new_sphere(point3(0, 1, 0), 1.0, m)) == NULL)
		return (ERROR);
    if (add_object(world, sp) == ERROR)
		return (ERROR);
    if ((m = new_lambertian(color3(0.4, 0.2, 0.1))) == NULL)
		return (ERROR);
	if ((sp = new_sphere(point3(-4, 1, 0), 1.0, m)) == NULL)
		return (ERROR);
	if (add_object(world, sp) == ERROR)
		return (ERROR);
	if ((m = new_metal(color3(0.7, 0.6, 0.5), 0)) == NULL)
		return (ERROR);
	if ((sp = new_sphere(point3(4, 1, 0), 1.0, m)) == NULL)
		return (ERROR);
	if (add_object(world, sp) == ERROR)
		return (ERROR);
	return (ERROR_NONE);
}
