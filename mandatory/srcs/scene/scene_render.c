#include "scene_internal.h"
#include <stdio.h>


void	render_one_layer(t_scene *scene, int layer_cnt)
{
	t_color3	old_color;
	t_color3	new_color;
	int			x;
	int			y;

	x = 0;
	while (x < scene->img->width)
	{
		y = 0;
		while (y < scene->img->height)
		{
			new_color = sampled_color(scene, x, y);
			old_color = get_pixel_color(scene->img, x, y);
			new_color = v3_div(\
							v3_add(v3_mul(old_color, layer_cnt), new_color), \
							(layer_cnt + 1));
			put_pixel_to_image(scene->img, x, y, new_color);
			y++;
		}
		x++;
	}
}

void	apply_gamma_correction(t_image *img)
{
	t_color3	old_color;
	t_color3	new_color;
	int			x;
	int			y;

	x = 0;
	while (x < img->width)
	{
		y = 0;
		while (y < img->height)
		{
			old_color = get_pixel_color(img, x, y);
			new_color.x = sqrt(old_color.x);
			new_color.y = sqrt(old_color.y);
			new_color.z = sqrt(old_color.z);
			put_pixel_to_image(img, x, y, new_color);
			y++;
		}
		x++;
	}
}

int	render_scene(void *minirt)
{
	t_mlx			*mlx;
	t_scene			*scene;
	t_render_status	*render_stat;
	int				i;

	mlx = &((t_minirt *)minirt)->mlx;
	scene = &((t_minirt *)minirt)->scene;
	render_stat = &((t_minirt *)minirt)->status;
	if (render_stat->is_done == true)
		return (SUCCESS);
	i = 0;
	while (i < PUT_IMG_TERM && render_stat->layer_cnt < SAMPLES_PER_PIXEL)
	{
		render_one_layer(scene, render_stat->layer_cnt);
		render_stat->layer_cnt++;
		i++;
	}
	printf("%d : rendering...\n", render_stat->layer_cnt);
	if (render_stat->layer_cnt == SAMPLES_PER_PIXEL)
	{
		apply_gamma_correction(&mlx->img);
		render_stat->is_done = true;
		printf("rendering done!\n");
	}
	mlx_put_image_to_window(mlx->conn, mlx->win, mlx->img.obj, 0, 0);
	return (SUCCESS);
}
