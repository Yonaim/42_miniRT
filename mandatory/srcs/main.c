#include "minirt.h"

static t_error	init_scene(t_scene *scene, int scene_num);
static void		render_scene(t_scene *scene);
static void		flush_scene(t_scene *scene);

int	main(void)
{
	t_scene	scene;

	if (init_scene(&scene, SCENE_NUMBER) == ERROR)
		return (1);
	render_scene(&scene);
	flush_scene(&scene);
	return (0);
}

static t_error	init_scene(t_scene *scene, int scene_num)
{
	t_construct_scene	construct_scene[] = {
	[SCENE0_MANY_BALLS] = construct_scene0,
	[SCENE1_TWO_CHECKER_BALLS] = construct_scene1,
	[SCENE2_SQUARE_LIGHT] = construct_scene2,
	[SCENE3_CORNELL_BOX] = construct_scene3
	};

	scene->width = WINDOW_WIDTH;
	scene->height = WINDOW_HEIGHT;
	init_camera(&scene->cam);
	if (init_world(&scene->world, INITIAL_WORLD_SIZE) == ERROR)
		return (ERROR);
	if (construct_scene[scene_num](scene) == ERROR)
		return (ERROR);
	return (ERROR_NONE);
}

static void	render_scene(t_scene *scene)
{
	t_color3	pixel_color;
	int			x;
	int			y;

	printf("P3\n");
	printf("%d %d\n", scene->width, scene->height);
	printf("255\n");
	y = scene->height - 1;
	while (y >= 0)
	{
		dprintf(2, "Scanlines remaining: %d\n", y);
		x = 0;
		while (x < scene->width)
		{
			pixel_color = get_pixel_color(scene, x, y);
			write_color(pixel_color);
			++x;
		}
		--y;
	}
	dprintf(2, ">> Done! <<\n");
}

static void	flush_scene(t_scene *scene)
{
	flush_world(&scene->world);
}


