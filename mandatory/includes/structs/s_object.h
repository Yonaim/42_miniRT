#ifndef S_OBJECT_H
# define S_OBJECT_H

# include <stdbool.h>
# include <stddef.h>
# include "typedef.h"

struct s_object
{
	t_hit_object		hit;
	t_destroy_object	destroy;
	t_material			*material;
};

struct s_object_point_light
{
	t_hit_object		hit;
	t_destroy_object	destroy;
	t_material			*material;
	t_point3			pos;
};

struct s_object_sphere
{
	t_hit_object		hit;
	t_destroy_object	destroy;
	t_material			*material;
	t_point3			center;
	double				radius;
};

struct s_object_disk
{
	t_hit_object		hit;
	t_destroy_object	destroy;
	t_material			*material;
	t_point3			center;
	double				radius;
	t_vector3			normal;
};

struct s_object_tube
{
	t_hit_object		hit;
	t_destroy_object	destroy;
	t_material			*material;
	t_point3			center;
	double				radius;
	double				height;
	t_vector3			orient;
};

struct s_object_cylinder
{
	t_hit_object		hit;
	t_destroy_object	destroy;
	t_material			*material;
	t_object_list		faces;
};

struct s_object_plane
{
	t_hit_object		hit;
	t_destroy_object	destroy;
	t_material			*material;
	t_point3			point;
	t_vector3			normal;
};

struct s_object_xy_rectangle
{
	t_hit_object		hit;
	t_destroy_object	destroy;
	t_material			*material;
	double				x0;
	double				x1;
	double				y0;
	double				y1;
	double				k;
};

struct s_object_xz_rectangle
{
	t_hit_object		hit;
	t_destroy_object	destroy;
	t_material			*material;
	double				x0;
	double				x1;
	double				z0;
	double				z1;
	double				k;
};

struct s_object_yz_rectangle
{
	t_hit_object		hit;
	t_destroy_object	destroy;
	t_material			*material;
	double				y0;
	double				y1;
	double				z0;
	double				z1;
	double				k;
};

struct s_object_box
{	
	t_hit_object		hit;
	t_destroy_object	destroy;
	t_material			*material;
	t_point3			p_min;
	t_point3			p_max;
	t_object_list		faces;
};

#endif
