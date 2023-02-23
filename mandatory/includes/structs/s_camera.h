#ifndef S_CAMERA_H
# define S_CAMERA_H

# include "libmath.h"

typedef struct s_viewport
{
	double			aspect_ratio;
		// width / height
	double			width;
	double			height;
	double			fov;
}	t_viewport;

typedef struct s_base_vector
{
	t_vector3		dir;
	t_vector3		up;
	t_vector3		right;
}	t_base_vector;

typedef struct s_focus_plane
{
	double			dist;
	t_vector3		horiz;
	t_vector3		vert;
	t_vector3		bottom_left;
}	t_focus_plane;

typedef struct s_camera
{
	t_viewport		viewport;
	t_point3		origin;
	double			lens_radius;
	t_base_vector	base;
	t_focus_plane	focus;
}	t_camera;

#endif