#include "scene_internal.h"
#include <fcntl.h>

void	init_scene(t_scene *scene, t_image *img, char *path)
{
	const int	fd = open(path, O_RDONLY);

	if (fd < 0)
		handle_error("Error: open file failed\n");
	if (init_object_arr(&scene->world.objects, \
								INITIAL_OBJECT_ARR_SIZE) == FAILURE)
		handle_error(ERRMSG_MALLOC_FAILED);
	parse_scene(scene, fd);
	init_camera(&scene->cam);
	scene->img = img;
}
