#include <stddef.h>
#include "libmath.h"
#include "s_material.h"
#include "s_object.h"
#include "s_world.h"
#include "s_texture.h"
#include "s_camera.h"
#include "constants.h"
#include "material.h"
#include "texture.h"
#include "object.h"
#include "world.h"
#include "typedef.h"

static void	set_scene1_camera(t_camera *cam);

t_error	construct_scene1(t_world *world, t_camera *cam)
{
	t_texture	*texture;
	t_material	*material;
	t_object	*sp;

	texture = new_checker_solid(color3(0.2, 0.3, 0.1), color3(0.9, 0.9, 0.9));
	if (texture == NULL)
		return (ERROR);
	set_scene1_camera(cam);
	material = new_lambertian(texture);
	if ((sp = new_sphere(point3(0, -10, 0), 10, material)) == NULL)
		return (ERROR);
	if (add_object(world, sp) == ERROR)
		return (ERROR);
	texture = new_checker_solid(color3(0.2, 0.3, 0.1), color3(0.9, 0.9, 0.9));
	material = new_lambertian(texture);
	if ((sp = new_sphere(point3(0, 10, 0), 10, material)) == NULL)
		return (ERROR);
	if (add_object(world, sp) == ERROR)
		return (ERROR);
	return (ERROR_NONE);
}

void	set_scene1_camera(t_camera *cam)
{
	cam->lens_radius = 0.1 / 2;
	cam->viewport.fov = 40.0;
	cam->origin = point3(13, 2, 3);
	cam->base.dir = v3_sub(cam->origin, point3(0, 0, 0));
	// 아래 세 줄은 init camera basis 함수랑 동일함
	cam->base.dir = v3_normalize(cam->base.dir);
	cam->base.right = v3_normalize(v3_cross(UP_VECTOR, cam->base.dir));
	cam->base.up = v3_cross(cam->base.dir, cam->base.right);
}