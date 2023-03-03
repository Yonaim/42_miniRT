#ifndef S_INFO_ELEMENT_H
# define S_INFO_ELEMENT_H

# include "typedef.h"
# include "color.h"

typedef struct s_info_ambient_light			t_info_ambient_light;
typedef struct s_info_camera				t_info_camera;
typedef struct s_info_object_point_light	t_info_object_point_light;
typedef struct s_info_object_sphere			t_info_object_sphere;
typedef struct s_info_object_cylinder		t_info_object_cylinder;
typedef struct s_info_object_cone			t_info_object_cone;
typedef struct s_info_object_plane			t_info_object_plane;
typedef struct s_info_object_box			t_info_object_box;

enum e_element_types
{
	// ELEMENT_NONE,
	ELEMENT_AMBIENT,
	ELEMENT_CAMERA,
	ELEMENT_LIGHT,
	ELEMENT_PLANE,
	ELEMENT_SPHERE,
	ELEMENT_CYLINDER,
	ELEMENT_CONE,
	ELEMENT_BOX,
};

enum e_material_types
{
	// MATERIAL_NONE,
	MATERIAL_LAMBERTIAL,
	MATERIAL_METAL,
	MATERIAL_DIELECTRIC,
	MATERIAL_EMMISIVE,
	MATERIAL_RANDOM,
};

enum e_texture_types
{
	// TEXTURE_NONE,
	TEXTURE_SOLID,
	TEXTURE_CHECKER,
	TEXTURE_IMAGE
};

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

struct s_info_object_cylinder
{
	t_point3	center;
	double		radius;
	double		height;
	t_vector3	orient;
	int			material_type;
	int			texture_type;
	t_color3	rgb;
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
