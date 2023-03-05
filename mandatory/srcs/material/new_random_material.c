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
	t_color3	color;
	t_texture	*texture;
	t_material	*material;

	color = v3_random(0, 255.999);
	texture = new_solid(color);
	material = new_lambertian(texture);
	return (material);
}

static t_material	*random_metal(void)
{
	t_color3	color;
	double		fuzz;
	t_material	*material;

	color = v3_random(150, 255.9);
	fuzz = random_double_range(0, 0.5);
	material = new_metal(color, fuzz);
	return (material);
}

static t_material	*random_dielectric(void)
{
	t_material	*material;

	material = new_dielectric(1.5);
	return (material);
}
