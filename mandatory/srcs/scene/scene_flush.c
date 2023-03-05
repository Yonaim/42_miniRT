#include "scene_internal.h"
#include <stdlib.h>

void	flush_scene(t_scene *scene)
{
	clear_object_arr(&scene->world.objects);
	free(scene->img->tmp_data);
}
