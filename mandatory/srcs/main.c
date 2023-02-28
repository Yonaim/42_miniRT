#include "minirt.h"

int	main(int argc, char *argv[])
{
	t_mlx	mlx;
	t_scene	scene;

	if (argc != 2)
		return (handle_error(ERRMSG_ARG_CNT));
	init_mlx(&mlx, &mlx.img);
	init_scene(&scene, &mlx.img, argv[1]);
	render_scene(&mlx, &scene);
	flush_scene(&scene);
	// esc, red button 관련 hook 함수 추가
	// mlx_put_image_to_window(mlx.conn, mlx.win, mlx.img.obj, 0, 0);
	mlx_loop(mlx.conn);
	return (0);
}
