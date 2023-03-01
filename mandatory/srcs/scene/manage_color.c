#include "scene_internal.h"

void	get_sampled_color(t_color3 *sampled_color, t_scene *scene, int x, int y)
{
	t_ray	ray;
	double	u;
	double	v;

	u = (x + random_double()) / (scene->img->width - 1);
	v = (y + random_double()) / (scene->img->height - 1);
	ray = primary_ray(&scene->cam, u, v);
	*sampled_color = traced_color(&ray, &scene->world, 0);
}

void	get_stored_color(t_color3 *stored_color, t_image *img, int x, int y)
{
	const int	offset = y * img->width + x;

	*stored_color = img->tmp_data[offset];
}

void	calculate_average_color(\
			t_color3 *stored_color, t_color3 *sampled_color, int stored_cnt)
{
	*stored_color = v3_add(v3_mul(*stored_color, stored_cnt), *sampled_color);
	*stored_color = v3_div(*stored_color, stored_cnt + 1);
}

void	update_stored_color(\
			t_image *img, t_color3 *stored_color, int x, int y)
{
	const int	offset = y * img->width + x;

	img->tmp_data[offset] = *stored_color;
}
