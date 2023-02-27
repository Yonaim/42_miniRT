#include "shading_internal.h"

t_color3	sampled_color(t_scene *scene, int x, int y)
{
	t_ray	ray;
	double	u;
	double	v;

	u = (x + random_double()) / (scene->img->width - 1);
	v = (y + random_double()) / (scene->img->height - 1);
	ray = primary_ray(&scene->cam, u, v);
	return (traced_color(&ray, &scene->world, MAX_DEPTH));
}

static void	gamma_correction(t_color3 *color)
{
	color->x = sqrt(color->x);
	color->y = sqrt(color->y);
	color->z = sqrt(color->z);
}

t_color3	get_pixel_color(t_scene *scene, int x, int y)
{
	t_color3	pixel_color;
	int			i;

	i = 0;
	pixel_color = (t_color3)vector3(0, 0, 0);
	while (i < SAMPLES_PER_PIXEL)
	{
		pixel_color = v3_add(pixel_color, sampled_color(scene, x, y));
		i++;
	}
	pixel_color = v3_div(pixel_color, SAMPLES_PER_PIXEL);
	gamma_correction(&pixel_color);
	return (pixel_color);
}
