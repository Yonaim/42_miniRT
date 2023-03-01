# include "scene_internal.h"

void	flush_scene(t_scene *scene)
{
	flush_object_arr(&scene->world.objects);
	free(scene->img->buff);
}
