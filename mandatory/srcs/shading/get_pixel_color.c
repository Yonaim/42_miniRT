#include "shading_internal.h"

static t_color	sampled_color(t_ray_tracing *rt, int x, int y)
{
	t_ray	ray;
	double	u;
	double	v;

	u = (x + random_double()) / (rt->mlx.img.width - 1);
	v = (y + random_double()) / (rt->mlx.img.height - 1);
	ray = primary_ray(&rt->cam, u, v);
	return (traced_color(&ray, &rt->world, MAX_DEPTH));
}

static void	gamma_correction(t_color *color)
{
	color->x = sqrt(color->x);
	color->y = sqrt(color->y);
	color->z = sqrt(color->z);
}

t_color	get_pixel_color(t_ray_tracing *rt, int x, int y)
{
	t_color	pixel_color;
	int		i;

	i = 0;
	pixel_color = (t_color)vector3(0, 0, 0);
	while (i < SAMPLES_PER_PIXEL)
	{
		pixel_color = v3_add(pixel_color, sampled_color(rt, x, y));
		i++;
	}
	pixel_color = v3_div(pixel_color, SAMPLES_PER_PIXEL);
	gamma_correction(&pixel_color);
	return (pixel_color);
}
