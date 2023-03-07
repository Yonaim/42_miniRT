# include "scene_internal.h"

void	init_scene(t_scene *scene, t_image *img, char *path)
{
	if (init_world(&scene->world, INITIAL_OBJ_ARR_SIZE) == FAILURE)
		handle_error(ERRMSG_MALLOC_FAILED);
	if (parse_scene(scene, path) == FAILURE)
		handle_error(ERRMSG_PARSE);
	scene->img = img;
	init_camera(&scene->cam);
	init_mixture_pdf(&scene->world.mixture_pdf, &scene->world.lights);
}
