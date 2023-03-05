# include "scene_internal.h"
# include <fcntl.h>

void	init_scene(t_scene *scene, t_image *img, char *path)
{
	const int	fd = open(path, O_RDONLY);
	t_info_arr	*infos;

	if (fd < 0)
		handle_error("Error: open file failed\n");
	if (init_dynamic_arr(infos, INITIAL_INFO_ARR_SIZE) == FAILURE \
		|| init_object_arr(&scene->world.objects, \
								INITIAL_OBJECT_ARR_SIZE) == FAILURE)
		handle_error(ERRMSG_MALLOC_FAILED);
	parse_scene(scene, fd);
}
