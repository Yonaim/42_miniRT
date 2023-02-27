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

static void		set_scene4_camera(t_camera *cam);
static t_error	set_scene4_objects(t_world *world);
static t_error	scene4_add_left_wall(t_world *world);
static t_error	scene4_add_right_wall(t_world *world);
static t_error	scene4_add_bottom_wall(t_world *world);
static t_error	scene4_add_top_wall(t_world *world);
static t_error	scene4_add_middle_wall(t_world *world);
static t_error	scene4_add_rectangle_light(t_world *world);
static t_error	scene4_add_boxes(t_world *world);

t_error	construct_scene4(t_scene *scene)
{
	scene->width = 600;
	scene->height = 600;
	set_scene4_camera(&scene->cam);
	if (set_scene4_objects(&scene->world) == ERROR)
		return (ERROR);
	return (ERROR_NONE);
}

void	set_scene4_camera(t_camera *cam)
{
	cam->lens_radius = 0;
	cam->origin = point3(278, 278, -800);
	// basis vector 설정
	cam->base.dir = v3_sub(cam->origin, point3(278, 278, 0));
	cam->base.dir = v3_normalize(cam->base.dir);
	cam->base.right = v3_normalize(v3_cross(UP_VECTOR, cam->base.dir));
	cam->base.up = v3_cross(cam->base.dir, cam->base.right);
	// viewport 설정
	cam->viewport.aspect_ratio = 1.0;
	cam->viewport.fov = 40.0;
	cam->viewport.width = 2 * tan(degree_to_radian(cam->viewport.fov) / 2);
	cam->viewport.height = cam->viewport.width / cam->viewport.aspect_ratio;
	// focusplane 설정
	cam->focus.dist = FOCAL_DISTANCE;
	cam->focus.horiz = v3_mul(cam->base.right, cam->focus.dist * cam->viewport.width);
	cam->focus.vert = v3_mul(cam->base.up, cam->focus.dist * cam->viewport.height);
	cam->focus.bottom_left = \
		v3_sub(\
			v3_add(cam->origin, v3_mul(cam->base.dir, -cam->focus.dist)), \
			v3_div(v3_add(cam->focus.horiz, cam->focus.vert), 2));
}

t_error set_scene4_objects(t_world *world)
{
	world->background_color = color3(0, 0, 0);
	if (scene4_add_boxes(world) == ERROR)
		return (ERROR);
	if (scene4_add_left_wall(world) == ERROR)
		return (ERROR);
	if (scene4_add_right_wall(world) == ERROR)
		return (ERROR);
	if (scene4_add_bottom_wall(world) == ERROR)
		return (ERROR);
	if (scene4_add_top_wall(world) == ERROR)
		return (ERROR);
	if (scene4_add_middle_wall(world) == ERROR)
		return (ERROR);
	if (scene4_add_rectangle_light(world) == ERROR)
		return (ERROR);
	return (ERROR_NONE);
}

static t_error	scene4_add_boxes(t_world *world)
{
	t_texture	*texture;
	t_material	*material;
	t_object	*box;

	if ((texture = new_solid(COLOR_WHITE)) == NULL)
		return (ERROR);
	if ((material = new_lambertian(texture)) == NULL)
		return (ERROR);
	if ((box = new_box(point3(130, 0, 65), point3(295, 165, 230), material)) \
																		== NULL)
		return (ERROR);
	if (add_object(&world->objects, box) == ERROR)
		return (ERROR);
	if ((texture = new_solid(COLOR_WHITE)) == NULL)
		return (ERROR);
	if ((material = new_lambertian(texture)) == NULL)
		return (ERROR);
	if ((box = new_box(point3(265, 0, 295), point3(430, 330, 460), material)) \
																		== NULL)
		return (ERROR);
	if (add_object(&world->objects, box) == ERROR)
		return (ERROR);
	return (ERROR_NONE);
}

static t_error	scene4_add_left_wall(t_world *world)
{
	t_texture		*texture;
	t_material		*material;
	t_object		*wall;
	const double	y[2] = {0, 555};
	const double	z[2] = {0, 555};
	const double	k = 555;

	texture = new_solid(COLOR_GREEN);
	if (texture == NULL)
		return (ERROR);
	material = new_lambertian(texture);
	if ((wall = new_yz_rectangle(y, z, k, material)) == NULL)
		return (ERROR);
	if (add_object(&world->objects, wall) == ERROR)
		return (ERROR);
	return (ERROR_NONE);
}

static t_error	scene4_add_right_wall(t_world *world)
{
	t_texture		*texture;
	t_material		*material;
	t_object		*wall;
	const double	y[2] = {0, 555};
	const double	z[2] = {0, 555};
	const double	k = 0;

	texture = new_solid(COLOR_RED);
	if (texture == NULL)
		return (ERROR);
	material = new_lambertian(texture);
	if ((wall = new_yz_rectangle(y, z, k, material)) == NULL)
		return (ERROR);
	if (add_object(&world->objects, wall) == ERROR)
		return (ERROR);
	return (ERROR_NONE);
}

static t_error	scene4_add_rectangle_light(t_world *world)
{
	t_material		*material;
	t_object		*light;
	const double	x[2] = {213, 343};
	const double	z[2] = {227, 332};
	const double	k = 554;

	material = new_emmisive(COLOR_LIGHT);
	if ((light = new_xz_rectangle(x, z, k, material)) == NULL)
		return (ERROR);
	if (add_object(&world->objects, light) == ERROR)
		return (ERROR);
	return (ERROR_NONE);
}

static t_error	scene4_add_bottom_wall(t_world *world)
{
	t_texture		*texture;
	t_material		*material;
	t_object		*wall;
	const double	x[2] = {0, 555};
	const double	z[2] = {0, 555};
	const double	k = 0;

	texture = new_solid(COLOR_WHITE);
	if (texture == NULL)
		return (ERROR);
	material = new_lambertian(texture);
	if ((wall = new_xz_rectangle(x, z, k, material)) == NULL)
		return (ERROR);
	if (add_object(&world->objects, wall) == ERROR)
		return (ERROR);
	return (ERROR_NONE);
}

static t_error	scene4_add_top_wall(t_world *world)
{
	t_texture		*texture;
	t_material		*material;
	t_object		*wall;
	const double	x[2] = {0, 555};
	const double	z[2] = {0, 555};
	const double	k = 555;

	texture = new_solid(COLOR_WHITE);
	if (texture == NULL)
		return (ERROR);
	material = new_lambertian(texture);
	if ((wall = new_xz_rectangle(x, z, k, material)) == NULL)
		return (ERROR);
	if (add_object(&world->objects, wall) == ERROR)
		return (ERROR);
	return (ERROR_NONE);
}

static t_error	scene4_add_middle_wall(t_world *world)
{
	t_texture		*texture;
	t_material		*material;
	t_object		*wall;
	const double	x[2] = {0, 555};
	const double	y[2] = {0, 555};
	const double	k = 555;

	texture = new_solid(COLOR_WHITE);
	if (texture == NULL)
		return (ERROR);
	material = new_lambertian(texture);
	if ((wall = new_xy_rectangle(x, y, k, material)) == NULL)
		return (ERROR);
	if (add_object(&world->objects, wall) == ERROR)
		return (ERROR);
	return (ERROR_NONE);
}
