#ifndef S_OBJECT_H
# define S_OBJECT_H

# include <stdbool.h>
# include <stddef.h>
# include "libmath.h"
# include "s_material.h"
# include "s_ray.h"
# include "s_hit_record.h"

typedef struct s_object	t_object;
typedef bool			(*t_hit)(\
								t_object *self, t_ray *ray, \
								t_hit_record *h_rec, double t_max);

enum	e_cylinder_disk_type
{
	TOP,
	BOTTOM
};

struct s_object
{
	t_hit			hit;
	t_material		material;
};

typedef struct s_object_point_light
{
	t_hit			hit;
	t_material		material;
	t_point3		pos;
}	t_object_point_light;

typedef struct s_object_sphere
{
	t_hit			hit;
	t_material		material;
	t_point3		center;
	double			radius;
}	t_object_sphere;

typedef struct s_object_disk
{
	t_hit			hit;
	t_material		material;
	t_point3		center;
	double			radius;
	t_vector3		normal;
}	t_object_disk;

typedef struct s_object_cylinder
{
	t_hit			hit;
	t_material		material;
	t_point3		center;
	double			radius;
	double			height;
	t_vector3		orient;
	t_object_disk	disks[2];
}	t_object_cylinder;

typedef struct s_object_plane
{
	t_hit			hit;
	t_material		material;
	t_point3		point;
	t_vector3		normal;
}	t_object_plane;

#endif
