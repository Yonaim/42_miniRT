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

static void		set_scene2_camera(t_camera *cam);
static t_error	set_scene2_objects(t_world *world);
static t_error	add_ground_sphere(t_world *world);
static t_error	add_middle_sphere(t_world *world);
static t_error	add_diff_light(t_world *world);

t_error	construct_scene2(t_scene *scene)
{
	set_scene2_camera(&scene->cam);
	if (set_scene2_objects(&scene->world) == ERROR)
		return (ERROR_NONE);
	return (ERROR);
}

t_error	set_scene2_objects(t_world *world)
{
	world->background_color = color3(0, 0, 0);
	if (add_ground_sphere(world) == ERROR)
		return (ERROR);
	if (add_middle_sphere(world) == ERROR)
		return (ERROR);
	if (add_diff_light(world) == ERROR)
		return (ERROR);
	return (ERROR_NONE);
}

void	set_scene2_camera(t_camera *cam)
{
	cam->lens_radius = 0.1 / 2;
	cam->origin = point3(26, 3, 10);
	// camera basis 설정
	cam->base.dir = v3_sub(cam->origin, point3(0, 2, 0));
	cam->base.dir = v3_normalize(cam->base.dir);
	cam->base.right = v3_normalize(v3_cross(UP_VECTOR, cam->base.dir));
	cam->base.up = v3_cross(cam->base.dir, cam->base.right);
	// viewport 설정
	cam->viewport.fov = 30.0;
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

t_error	add_ground_sphere(t_world *world)
{
	t_texture	*texture;
	t_material	*material;
	t_object	*sp;

	texture = new_checker_solid(color3(0.2, 0.3, 0.1), color3(0.9, 0.9, 0.9));
	if (texture == NULL)
		return (ERROR);
	material = new_lambertian(texture);
	if ((sp = new_sphere(point3(0, -1000, 0), 1000, material)) == NULL)
		return (ERROR);
	if (add_object(&world->objects, sp) == ERROR)
		return (ERROR);
	return (ERROR_NONE);
}

t_error	add_middle_sphere(t_world *world)
{
	t_texture	*texture;
	t_material	*material;
	t_object	*sp;

	texture = new_solid(color3(0.5, 0.5, 0.5));
	material = new_lambertian(texture);
	if ((sp = new_sphere(point3(0, 2, 0), 2, material)) == NULL)
		return (ERROR);
	if (add_object(&world->objects, sp) == ERROR)
		return (ERROR);
	return (ERROR_NONE);
}

t_error	add_diff_light(t_world *world)
{
	t_material		*material;
	t_object		*rc;
	double	x[2] = {3, 5};
	double	y[2] = {1, 3};
	double	k = -2;

	material = new_emmisive(color3(4, 4, 4));
	if ((rc = new_xy_rectangle(x, y, k, material)) == NULL)
		return (ERROR);
	if (add_object(&world->objects, rc) == ERROR)
		return (ERROR);
	return (ERROR_NONE);
}
