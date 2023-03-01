#include "scene_internal.h"
#include <stdio.h>

void	gamma_correction(t_color3 *color)
{
	color->x = sqrt(color->x);
	color->y = sqrt(color->y);
	color->z = sqrt(color->z);
}

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
			old_color = get_pixel_color(scene->img, scene->img->buff, x, y);
			new_color = v3_div(\
							v3_add(v3_mul(old_color, layer_cnt), new_color), \
							(layer_cnt + 1));
			update_buff_pixel_color(scene->img, x, y, new_color);
			gamma_correction(&new_color);
			put_pixel_to_image(scene->img, x, y, new_color);
			y++;
		}
		x++;
	}
}

int	render_scene(void *minirt)
{
	t_mlx		*mlx;
	t_scene		*scene;
	int			*layer_cnt;
	int			i;

	mlx = &((t_minirt *)minirt)->mlx;
	scene = &((t_minirt *)minirt)->scene;
	layer_cnt = &((t_minirt *)minirt)->layer_cnt;
	if ((*layer_cnt) == SAMPLES_PER_PIXEL)
		return (SUCCESS);
	i = 0;
	while (i < PUT_IMG_TERM && (*layer_cnt) < SAMPLES_PER_PIXEL)
	{
		render_one_layer(scene, (*layer_cnt));
		(*layer_cnt)++;
		i++;
	}
	printf("%d : rendering...\n", (*layer_cnt));
	if ((*layer_cnt) == SAMPLES_PER_PIXEL)
		printf("rendering done!\n");
	mlx_put_image_to_window(mlx->conn, mlx->win, mlx->img.obj, 0, 0);
	return (SUCCESS);
}
