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

t_color	get_pixel_color(t_ray_tracing *rt, int x, int y)
{
	t_color	pixel_color;
	int		i;

	i = 0;
	pixel_color = (t_color)vector(0, 0, 0);
	while (i < SAMPLES_PER_PIXEL)
	{
		pixel_color = v_add(pixel_color, sampled_color(rt, x, y));
		i++;
	}
	return (pixel_color);
}
