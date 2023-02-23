#include "minirt.h"

// init하는 함수들 호출
void	init_ray_tracing(t_mlx *mlx, t_scene *scene, char *path)
{
	// init하는 함수들 호출
	if (parse_scene(scene, path) == FAILURE)
		handle_error(ERRMSG_PARSE);
	init_camera(scene->cam, &mlx->img);
	init_mlx(mlx);
}

// 모든 픽셀 값  구하기	
void	do_rendering(t_mlx *mlx, t_scene *scene)
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
	mlx_put_image_to_window(rt->mlx.conn, rt->mlx.win, img->obj, 0, 0);
}

// 종료 전 할당한 메모리 정리
void	flush_scene(t_scene *scene)
{
}

int	main(int argc, char *argv)
{
	t_mlx	mlx;
	t_scene	scene;

	if (argc != 2)
		return (handle_error(ERRMSG_ARG_CNT));
	init_ray_tracing(&mlx, &scene, argv[1]);
	do_rendering(&mlx, &scene);
	flush_scene(&scene);
	// esc, red button 관련 hook 함수 추가
	return (0);
}
