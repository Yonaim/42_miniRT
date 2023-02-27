#include "scene_internal.h"

void	render_one_layer(t_scene *scene)
{
	t_color3	old_pixel_color;
	t_color3	new_pixel_color;
	int			x;
	int			y;

	x = 0;
	while (x < scene->img->width)
	{
		y = 0;
		while (y < scene->img->height)
		{
			new_pixel_color = sampled_color(scene, x, y);
			old_pixel_color = get_pixel_color(scene->img, x, y);
			new_pixel_color = v3_add(old_pixel_color, new_pixel_color);
			put_pixel_to_image(scene->img, x, y, new_pixel_color);
			y++;
		}
		x++;
	}
}

void	apply_gamma_correction(t_image *img)
{
	t_color3	old_pixel_color;
	t_color3	new_pixel_color;
	int			x;
	int			y;

	x = 0;
	while (x < img->width)
	{
		y = 0;
		while (y < img->height)
		{
			old_pixel_color = get_pixel_color(img, x, y);
			new_pixel_color.x = sqrt(old_pixel_color.x);
			new_pixel_color.y = sqrt(old_pixel_color.y);
			new_pixel_color.z = sqrt(old_pixel_color.z);
			put_pixel_to_image(img, x, y, new_pixel_color);
			y++;
		}
		x++;
	}
}

void	render_scene(t_mlx *mlx, t_scene *scene)
{
	t_color3	sample_color;
	int			sample_cnt;
	int			term;

	sample_cnt = 0;
	while (sample_cnt < SAMPLES_PER_PIXEL)
	{
		term = 0;
		while (term < PUT_IMG_TERM)
		{
			render_one_layer(scene);
			sample_cnt++;
			if (sample_cnt == SAMPLES_PER_PIXEL)
				break ;
			term++;
		}
		mlx_put_image_to_window(mlx->conn, mlx->win, mlx->img.obj, 0, 0);
	}
	apply_gamma_correction(&mlx->img);
	mlx_put_image_to_window(mlx->conn, mlx->win, mlx->img.obj, 0, 0);
}
