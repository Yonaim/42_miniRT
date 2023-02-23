#include "s_mlx.h"
#include "camera.h"
#include "libmath.h"
#include "constants.h"

static void	init_camera_basis(t_camera *cam)
{
	cam->base.dir = v3_normalize(cam->base.dir);
	cam->base.right = v3_normalize(v3_cross(UP_VECTOR, cam->base.dir));
	cam->base.up = v3_cross(cam->base.dir, cam->base.right);
}

static void	init_camera_viewport(t_viewport *viewport, t_image *image)
{
	viewport->aspect_ratio = (double)image->width / image->height;
	viewport->width = 2 * tan(deg_to_rad(viewport->fov) / 2);
	viewport->height = viewport->width / viewport->aspect_ratio;
}

static void	init_camera_focus_plane(t_camera *cam, t_focus_plane *focus)
{
	focus->dist = FOCAL_DISTANCE;
	focus->horiz = v3_mul(cam->base.right, focus->dist * cam->viewport.width);
	focus->vert = v3_mul(cam->base.up, focus->dist * cam->viewport.height);
	focus->bottom_left = v3_sub(\
							v3_sub(\
								v3_sub(cam->origin, v3_div(focus->horiz, 2)), \
								v3_div(focus->vert, 2)), \
							v3_mul(cam->base.dir, focus->dist));
}

void	init_camera(t_camera *cam, t_image *img)
{
	init_camera_basis(cam);
	init_camera_viewport(&cam->viewport, img);
	init_camera_focus_plane(cam, &cam->focus);
	cam->lens_radius = APERTURE / 2;
}
