#ifndef S_INFO_ELEMENT_H
# define S_INFO_ELEMENT_H

# include "typedef.h"
# include "color.h"

typedef struct s_info_ambient_light			t_info_ambient_light;
typedef struct s_info_camera				t_info_camera;
typedef struct s_info_object_point_light	t_info_object_point_light;
typedef struct s_info_object_sphere			t_info_object_sphere;
typedef struct s_info_object_disk			t_info_obejct_disk;
typedef struct s_info_object_tube			t_info_object_tube;
typedef struct s_info_object_cylinder		t_info_object_cylinder;
typedef struct s_info_object_cone			t_info_object_cone;
typedef struct s_info_object_plane			t_info_object_plane;
typedef struct s_info_object_box			t_info_object_box;

struct s_info_ambient_light
{
	double		brightness;
	int			material_type;
	int			texture_type;
	t_color3	rgb;
};

struct s_info_camera
{
	t_point3	origin;
	t_vector3	orient;
	int			fov;
};

struct s_info_object_point_light
{
	t_point3	pos;
	double		brightness;
	int			material_type;
	int			texture_type;
	t_color3	rgb;
};

struct s_info_object_sphere
{
	t_point3	center;
	double		radius;
	int			material_type;
	int			texture_type;
	t_color3	rgb;
};

struct s_info_object_disk
{
	t_point3	center;
	double		radius;
	t_vector3	orient;
	int			material_type;
	int			texture_type;
	t_color3	rgb;
};

struct s_info_object_tube
{
	t_point3	bottom_center;
	double		radius;
	t_vector3	orient;
	double		height;
	int			material_type;
	int			texture_type;
	t_color3	rgb;
};

struct s_info_object_cylinder
{
	t_info_object_disk	disk[2];
	t_info_object_tube	tube;
	int					material_type;
	int					texture_type;
	t_color3			rgb;
};

struct s_info_object_cone
{
	t_point3	center;
	double		radius;
	double		height;
	t_vector3	orient;
	int			material_type;
	int			texture_type;
	t_color3	rgb;
};

struct s_info_object_plane
{
	t_point3	point;
	t_vector3	normal;
	int			material_type;
	int			texture_type;
	t_color3	rgb;
};

struct s_info_object_box
{	
	t_point3	p_end1;
	t_point3	p_end2;
	int			material_type;
	int			texture_type;
	t_color3	rgb;
};

#endif
