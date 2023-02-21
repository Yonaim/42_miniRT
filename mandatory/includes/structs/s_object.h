#ifndef S_OBJECT_H
# define S_OBJECT_H

# include "libmath.h"
# include "s_material.h"

enum e_object_type {
	SPHERE,
	DISK,
	CYLINDER,
	PLANE
};

enum	e_cylinder_disk_type {
	TOP,
	BOTTOM
};

typedef struct s_point_light {
	t_point		pos;
	t_material	material;
}	t_point_light;

typedef struct s_sphere {
	t_point		center;
	double		radius;
	t_material	material;
}	t_sphere;

typedef struct s_disk {
	t_point		center;
	double		radius;
	t_vector	normal;
	t_material	material;
}	t_disk;

typedef struct s_cylinder {
	t_point		center;
	double		radius;
	double		height;
	t_vector	orient;
	t_disk		disks[2];
	t_material	material;
}	t_cylinder;

typedef struct s_plane {
	t_point		point;
	t_vector	normal;
	t_material	material;
}	t_plane;

typedef union u_object {
	t_sphere	sp;
	t_disk		dk;
	t_cylinder	cy;
	t_plane		pl;
}	t_object;

typedef struct s_object_array {
	int			*type;
	t_object	*data;
	int			alloc_size;
	int			used_size;
}	t_object_array;

#endif
