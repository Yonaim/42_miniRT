#ifndef S_CAMERA_H
# define S_CAMERA_H

# include "libmath.h"
# include "typedef.h"

struct s_viewport
{
	double			aspect_ratio;
	double			width;
	double			height;
	double			fov;
};

struct s_base_vector
{
	t_vector3		dir;
	t_vector3		up;
	t_vector3		right;
};

struct s_focus_plane
{
	double			dist;
	t_vector3		horiz;
	t_vector3		vert;
	t_vector3		bottom_left;
};

struct s_camera
{
	t_viewport		viewport;
	t_point3		origin;
	double			lens_radius;
	t_base_vector	base;
	t_focus_plane	focus;
};

#endif