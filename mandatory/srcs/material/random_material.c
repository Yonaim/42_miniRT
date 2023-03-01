#include "material_internal.h"

static t_material	*random_lambertian(void);
static t_material	*random_metal(void);
static t_material	*random_dielectric(void);

t_material	*new_random_material(void)
{
	double	rullet;

	rullet = random_double();
	if (rullet < 0.5)
		return (random_lambertian());
	else if (rullet < 0.8)
		return (random_metal());
	else
		return (random_dielectric());
}

static t_material	*random_lambertian(void)
{
	t_color3	albedo;
	t_texture	*texture;
	t_material	*material;

	albedo = v3_random(0, 1);
	texture = new_solid(albedo);
	material = new_lambertian(texture);
	return (material);
}

static t_material	*random_metal(void)
{
	t_color3	albedo;
	double		fuzz;
	t_material	*material;

	albedo = v3_random(0.5, 1);
	fuzz = random_double_range(0, 0.5);
	material = new_metal(albedo, fuzz);
	return (material);
}

static t_material	*random_dielectric(void)
{
	t_material	*material;

	material = new_dielectric(1.5);
	return (material);
}

