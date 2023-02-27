#ifndef S_OBJECT_H
# define S_OBJECT_H

# include <stdbool.h>
# include <stddef.h>
# include "typedef.h"

struct s_object
{
	t_material			*material;
	t_hit				hit;
	t_destroy_object	destroy;
};

struct s_object_point_light
{
	t_material			*material;
	t_hit				hit;
	t_destroy_object	destroy;
	t_point3			pos;
};

struct s_object_sphere
{
	t_material			*material;
	t_hit				hit;
	t_destroy_object	destroy;
	t_point3			center;
	double				radius;
};

struct s_object_disk
{
	t_material			*material;
	t_hit				hit;
	t_destroy_object	destroy;
	t_point3				center;
	double					radius;
	t_vector3				normal;
};

struct s_object_cylinder
{
	t_material			*material;
	t_hit				hit;
	t_destroy_object	destroy;
	t_object_list		faces;
	t_point3			center;
	double				radius;
	double				height;
	t_vector3			orient;
};

struct s_object_plane
{
	t_material			*material;
	t_hit				hit;
	t_destroy_object	destroy;
	t_point3			point;
	t_vector3			normal;
};

struct s_object_xy_rectangle
{
	t_material			*material;
	t_hit				hit;
	t_destroy_object	destroy;
	double				x0;
	double				x1;
	double				y0;
	double				y1;
	double				k;
};

struct s_object_xz_rectangle
{
	t_material			*material;
	t_hit				hit;
	t_destroy_object	destroy;
	double				x0;
	double				x1;
	double				z0;
	double				z1;
	double				k;
};

struct s_object_yz_rectangle
{
	t_material			*material;
	t_hit				hit;
	t_destroy_object	destroy;
	double				y0;
	double				y1;
	double				z0;
	double				z1;
	double				k;
};

struct s_object_box
{	
	t_material			*material;
	t_hit				hit;
	t_destroy_object	destroy;
	t_point3			p_min;
	t_point3			p_max;
	t_object_list		faces;
};

#endif
