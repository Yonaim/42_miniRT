#include "../parse_internal.h"

int	put_ambient_to_scene(t_info *info, t_scene *scene)
{
	const t_info_ambient_light *amb = (t_info_ambient_light *)info; 
	
	scene->world.background_color = v3_mul(amb->rgb, amb->brightness);
	return (1);
}

int	put_camera_to_scene(t_info *info, t_scene *scene)
{
	const t_info_camera *cam = (t_info_camera *)info; 
	
	scene->cam.basis.dir = v3_mul(cam->orient, -1);
	scene->cam.viewport.fov = cam->fov;
	scene->cam.origin = cam->origin;
	init_camera(&scene->cam);
	return (1);
}
