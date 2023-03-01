#ifndef S_INFO_ELEMENT_H
# define S_INFO_ELEMENT_H

# include "typedef.h"
# include "color.h"

typedef struct s_info_ambient_light			t_info_ambient_light;
typedef struct s_info_camera				t_info_camera;
typedef struct s_info_material				t_info_material;
typedef struct s_info_object_point_light	t_info_object_point_light;
typedef struct s_info_object_sphere			t_info_object_sphere;
typedef struct s_info_object_disk			t_info_object_disk;
typedef struct s_info_object_tube			t_info_object_tube;
typedef struct s_info_object_cylinder		t_info_object_cylinder;
typedef struct s_info_object_cone			t_info_object_cone;
typedef struct s_info_object_plane			t_info_object_plane;
typedef struct s_info_object_box			t_info_object_box;

enum e_element_types
{
	ELEMENT_AMBIENT,
	ELEMENT_CAMERA,
	ELEMENT_LIGHT,
	ELEMENT_PLANE,
	ELEMENT_SPHERE,
	ELEMENT_CYLINDER,
	ELEMENT_CONE,
	ELEMENT_BOX,
	ELEMENT_NONE
};

enum e_material_types
{
	MATERIAL_LAMBERTIAL,
	MATERIAL_METAL,
	MATERIAL_DIELECTRIC,
	MATERIAL_EMMISIVE,
	MATERIAL_RANDOM
};

enum e_texture_types
{
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

struct s_info_material
{
	int			material_type;
	int			texture_type;
	t_color3	rgb1;
	t_color3	rgb2;
	double		fuzz;
	double		refractive_idx;
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
	t_point3		center;
	double			radius;
	t_info_material	material;
};

struct s_info_object_disk
{
	t_point3		center;
	double			radius;
	t_vector3		orient;
	t_info_material	material;
};

struct s_info_object_tube
{
	t_point3		center;
	double			radius;
	t_vector3		orient;
	double			height;
	t_info_material	material;
};

struct s_info_object_cylinder
{
	t_info_object_disk	disk[2];
	t_info_object_tube	tube;
	t_info_material		material;
};

struct s_info_object_cone
{
	t_point3		center;
	double			radius;
	double			height;
	t_vector3		orient;
	t_info_material	material;
};

struct s_info_object_plane
{
	t_point3		point;
	t_vector3		normal;
	t_info_material	material;
};

struct s_info_object_box
{	
	t_point3		p_end1;
	t_point3		p_end2;
	t_info_material	material;
};

#endif
