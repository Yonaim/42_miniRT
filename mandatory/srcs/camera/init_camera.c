#include <math.h>
#include "s_mlx.h"
#include "camera.h"
#include "libmath.h"
#include "constants.h"

t_vector3	determine_up_vector(t_vector3 v)
{
	t_vector3	up_vector;

	up_vector = v3_normalize(v);
	if (fabs(v.z) > 0.9)
		up_vector = vector3(0, 1, 0);
	else
		up_vector = vector3(0, 0, 1);
	return (up_vector);
}

static void	init_camera_basis(t_camera *cam)
{
	t_vector3	up_vector;

	cam->basis.dir = v3_normalize(cam->basis.dir);
	up_vector = determine_up_vector(cam->basis.dir);
	cam->basis.right = v3_normalize(v3_cross(up_vector, cam->basis.dir));
	cam->basis.up = v3_cross(cam->basis.dir, cam->basis.right);
}

static void	init_camera_viewport(t_viewport *viewport)
{
	viewport->aspect_ratio = (double)WINDOW_WIDTH / WINDOW_HEIGHT;
	viewport->width = 2 * tan(degree_to_radian(viewport->fov) / 2);
	viewport->height = viewport->width / viewport->aspect_ratio;
}

static void	init_camera_focus_plane(t_camera *cam, t_focus_plane *focus)
{
	focus->dist = FOCAL_DISTANCE;
	focus->horiz = v3_mul(cam->basis.right, focus->dist * cam->viewport.width);
	focus->vert = v3_mul(cam->basis.up, focus->dist * cam->viewport.height);
	focus->bottom_left = \
		v3_sub(\
			v3_add(cam->origin, v3_mul(cam->basis.dir, -focus->dist)), \
			v3_div(v3_add(focus->horiz, focus->vert), 2));
}

void	init_camera(t_camera *cam)
{
	init_camera_basis(cam);
	init_camera_viewport(&cam->viewport);
	init_camera_focus_plane(cam, &cam->focus);
	cam->lens_radius = APERTURE / 2;
}
