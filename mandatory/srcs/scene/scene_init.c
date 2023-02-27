# include "scene_internal.h"

void	init_scene(t_scene *scene, t_image *img, char *path)
{
	if (init_object_arr(&scene->world.objects, INITIAL_OBJ_ARR_SIZE) == FAILURE)
		handle_error(ERRMSG_MALLOC_FAILED);
	if (parse_scene(scene, path) == FAILURE)
		handle_error(ERRMSG_PARSE);
	scene->img = img;
	init_camera(&scene->cam);
printf("cam info: \n");
printf("position: %f %f %f\n", \
		scene->cam.origin.x, scene->cam.origin.y, scene->cam.origin.z);
}
