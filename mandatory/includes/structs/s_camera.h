#ifndef S_CAMERA_H
# define S_CAMERA_H

# include "libmath.h"

typedef struct s_viewport
{
	double	aspect_ratio;
	double	width;
	double	height;
	double	fov;
}	t_viewport;

typedef struct s_base_vector
{
	t_vector	dir;
	t_vector	up;
	t_vector	right;
}	t_base_vector;

typedef struct s_focus_plane
{
	double		dist;
	t_vector	horiz;
	t_vector	vert;
	t_vector	bottom_left;
}	t_focus_plane;

typedef struct s_camera
{
	t_viewport		viewport;
	t_point			origin;
	t_point			look_at;
	double			lens_radius;
	t_base_vector	base;
	t_focus_plane	focus;
}	t_camera;

#endif