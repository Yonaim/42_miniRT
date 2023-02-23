#include "minirt.h"

void	init_ray_tracing(t_ray_tracing *rt, char *path)
{
	// init하는 함수들 호출
	if (parse_scene_info(rt, path) == FAILURE)
		handle_error(ERRMSG_PARSE);
	init_camera(rt->cam, &rt->mlx.img);
	init_mlx(rt->mlx);
}

void	do_rendering(t_ray_tracing *rt, t_image *img)
{
	// 모든 픽셀 값  구하기
	t_color	pixel_color;
	int		x;
	int		y;

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

void	flush_ray_tracing(t_ray_tracing *rt)
{
	// 종료 전 할당한 메모리 정리
}

int	main(int argc, char *argv)
{
	t_ray_tracing	rt;

	if (argc != 2)
		return (handle_error(ERRMSG_ARG_CNT));
	init_ray_tracing(&rt, argv[1]);
	do_rendering(&rt, &rt.mlx.img);
	flush_ray_tracing(&rt);
	// esc, red button 관련 hook 함수 추가
}
