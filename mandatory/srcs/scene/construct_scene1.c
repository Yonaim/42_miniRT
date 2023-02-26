#include <math.h>
#include <stddef.h>
#include "libmath.h"
#include "s_scene.h"
#include "s_material.h"
#include "s_object.h"
#include "s_world.h"
#include "s_texture.h"
#include "s_camera.h"
#include "constants.h"
#include "material.h"
#include "texture.h"
#include "object.h"
#include "object_arr.h"
#include "world.h"
#include "typedef.h"

static void	set_scene1_camera(t_camera *cam);
t_error	set_scene1_objects(t_world *world);

t_error	construct_scene1(t_scene *scene)
{
	set_scene1_camera(&scene->cam);
	if (set_scene1_objects(&scene->world) == ERROR)
		return (ERROR);
	return (ERROR_NONE);
}

t_error	set_scene1_objects(t_world *world)
{
	t_texture	*texture;
	t_material	*material;
	t_object	*sp;

	texture = new_checker_solid(color3(0.2, 0.3, 0.1), color3(0.9, 0.9, 0.9));
	if (texture == NULL)
		return (ERROR);
	material = new_lambertian(texture);
	if ((sp = new_sphere(point3(0, -10, 0), 10, material)) == NULL)
		return (ERROR);
	if (add_object(&world->objects, sp) == ERROR)
		return (ERROR);
	texture = new_checker_solid(color3(0.2, 0.3, 0.1), color3(0.9, 0.9, 0.9));
	material = new_lambertian(texture);
	if ((sp = new_sphere(point3(0, 10, 0), 10, material)) == NULL)
		return (ERROR);
	if (add_object(&world->objects, sp) == ERROR)
		return (ERROR);
	return (ERROR_NONE);
}

void	set_scene1_camera(t_camera *cam)
{
	cam->lens_radius = 0.1 / 2;
	cam->origin = point3(13, 2, 3);
	// camera_basis 설정
	cam->base.dir = v3_sub(cam->origin, point3(0, 0, 0));
	cam->base.dir = v3_normalize(cam->base.dir);
	cam->base.right = v3_normalize(v3_cross(UP_VECTOR, cam->base.dir));
	cam->base.up = v3_cross(cam->base.dir, cam->base.right);
	// viewport 설정
	cam->viewport.fov = 40.0;
	// cam->viewport.aspect_ratio = (double)WINDOW_WIDTH / WINDOW_HEIGHT;
	// cam->viewport.fov = FIELD_OF_VIEW;
	cam->viewport.width = 2 * tan(degree_to_radian(cam->viewport.fov) / 2);
	cam->viewport.height = cam->viewport.width / cam->viewport.aspect_ratio;
	// focus plane 설정
	// cam->focus.dist = FOCAL_DISTANCE;
	cam->focus.horiz = v3_mul(\
						cam->base.right, cam->focus.dist * cam->viewport.width);
	cam->focus.vert = v3_mul(\
						cam->base.up, cam->focus.dist * cam->viewport.height);
	cam->focus.bottom_left = \
			v3_sub(\
				v3_add(cam->origin, v3_mul(cam->base.dir, -cam->focus.dist)), \
				v3_div(v3_add(cam->focus.horiz, cam->focus.vert), 2));
}