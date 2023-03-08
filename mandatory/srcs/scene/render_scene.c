/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:19:21 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/09 04:11:08 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_internal.h"

static void	render_one_layer(t_scene *scene, int layer_cnt)
{
	t_color3	sampled_color;
	t_color3	stored_color;
	int			x;
	int			y;

	x = 0;
	while (x < scene->img->width)
	{
		y = 0;
		while (y < scene->img->height)
		{
			get_sampled_color(&sampled_color, scene, x, y);
			get_stored_color(&stored_color, scene->img, x, y);
			calculate_average_color(&stored_color, &sampled_color, layer_cnt);
			update_stored_color(scene->img, &stored_color, x, y);
			gamma_correction(&stored_color);
			put_pixel_to_image(scene->img, &stored_color, x, y);
			y++;
		}
		x++;
	}
}

int	render_scene(void *minirt)
{
	t_mlx			*mlx;
	t_scene			*scene;
	static int		layer_cnt;
	int				i;

	mlx = &((t_minirt *)minirt)->mlx;
	scene = &((t_minirt *)minirt)->scene;
	if (layer_cnt == SAMPLES_PER_PIXEL)
		return (SUCCESS);
	i = 0;
	while (i < PUT_IMG_TERM && layer_cnt < SAMPLES_PER_PIXEL)
	{
		render_one_layer(scene, layer_cnt);
		layer_cnt++;
		i++;
	}
	ft_printf("%d : rendering...\n", layer_cnt);
	if (layer_cnt == SAMPLES_PER_PIXEL)
		ft_printf("rendering done!\n");
	mlx_put_image_to_window(mlx->conn, mlx->win, mlx->img.obj, 0, 0);
	return (SUCCESS);
}
