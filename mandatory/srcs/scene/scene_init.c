# include "scene_internal.h"

void	init_scene(t_scene *scene, t_image *img, char *path)
{
	if (parse_scene(scene, path) == FAILURE)
		handle_error(ERRMSG_PARSE);
	scene->img = img;
	init_camera(&scene->cam);
}
