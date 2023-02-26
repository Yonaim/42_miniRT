#ifndef S_OBJECT_H
# define S_OBJECT_H

# include <stdbool.h>
# include <stddef.h>
# include "typedef.h"

enum	e_cylinder_disk_type
{
	TOP,
	BOTTOM
};

struct s_object
{
	t_hit				hit;
	t_material			*material;
	t_destroy_object	destroy;
};

struct s_object_point_light
{
	t_hit				hit;
	t_material			*material;
	t_destroy_object	destroy;
	t_point3			pos;
};

struct s_object_sphere
{
	t_hit				hit;
	t_material			*material;
	t_destroy_object	destroy;
	t_point3			center;
	double				radius;
};

struct s_object_disk
{
	t_hit				hit;
	t_material			*material;
	t_destroy_object	destroy;
	t_point3			center;
	double				radius;
	t_vector3			normal;
};

struct s_object_cylinder
{
	t_hit				hit;
	t_material			*material;
	t_destroy_object	destroy;
	t_point3			center;
	double				radius;
	double				height;
	t_vector3			orient;
	t_object_disk		disks[2];
};

struct s_object_plane
{
	t_hit				hit;
	t_material			*material;
	t_destroy_object	destroy;
	t_point3			point;
	t_vector3			normal;
};

};

#endif
