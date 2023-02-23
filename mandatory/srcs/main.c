#include "minirt.h"

static void	init_scene(t_scene *scene, char *path)
{
	if (parse_scene(scene, path) == FAILURE)
		handle_error(ERRMSG_PARSE);
	scene->width = IMG_WIDTH;
	scene->height = IMG_HEIGHT;
	init_camera(scene->cam);
}

static void	do_rendering(t_mlx *mlx, t_scene *scene)
{
	t_color3	pixel_color;
	int			x;
	int			y;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			pixel_color = get_pixel_color(rt, x, y);
			put_pixel_to_image(img, x, y, pixel_color);
			x++;
		}
		y++;
	}
}

// 종료 전 할당한 메모리 정리
static void	flush_scene(t_scene *scene)
{
}

int	main(int argc, char *argv)
{
	t_mlx	mlx;
	t_scene	scene;

	if (argc != 2)
		return (handle_error(ERRMSG_ARG_CNT));
	init_scene(&mlx, &scene, argv[1]);
	init_mlx(mlx);
	do_rendering(&mlx, &scene);
	flush_scene(&scene);
	// esc, red button 관련 hook 함수 추가
	mlx_put_image_to_window(mlx.conn, mlx.win, mlx.img->obj, 0, 0);
	return (0);
}
