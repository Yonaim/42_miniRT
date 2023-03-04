#ifndef S_INFO_ELEMENT_H
# define S_INFO_ELEMENT_H

# include "typedef.h"
# include "color.h"

typedef struct s_info						t_info;
typedef struct s_info_ambient_light			t_info_ambient_light;
typedef struct s_info_camera				t_info_camera;
typedef struct s_info_texture				t_info_texture;
typedef struct s_info_material				t_info_material;
typedef struct s_info_object_point_light	t_info_object_point_light;
typedef struct s_info_object_sphere			t_info_object_sphere;
typedef struct s_info_object_disk			t_info_object_disk;
typedef struct s_info_object_tube			t_info_object_tube;
typedef struct s_info_object_cylinder		t_info_object_cylinder;
typedef struct s_info_object_cone_lateral	t_info_object_cone_lateral;
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
	ELEMENT_DISK,
	ELEMENT_TUBE,
	ELEMENT_CYLINDER,
	ELEMENT_CONE,
	ELEMENT_CONE_LATERAL,
	ELEMENT_BOX,
	ELEMENT_NONE
};


enum e_material_types
{
	MATERIAL_LAMBERTIAN,
	MATERIAL_METAL,
	MATERIAL_DIELECTRIC,
	MATERIAL_EMMISIVE,
	MATERIAL_RANDOM,
	MATERIAL_NONE,
};

enum e_texture_types
{
	TEXTURE_SOLID,
	TEXTURE_CHECKER,
	TEXTURE_IMAGE,
	TEXTURE_NONE,
};

# define ELEMENT_TYPE_COUNT		11
# define MATERIAL_TYPE_COUNT	5
# define TEXTURE_TYPE_COUNT		3

# define DEFAULT_MATERIAL		MATERIAL_LAMBERTIAN
# define DEFAULT_TEXTURE		TEXTURE_SOLID

struct s_info
{
};

struct s_info_ambient_light
{
	double		brightness;
	t_color3	rgb;
};

struct s_info_camera
{
	t_point3	origin;
	t_vector3	orient;
	int			fov;
};

struct s_info_texture
{
	int			type;
	t_color3	rgb1;
	t_color3	rgb2;
};

struct s_info_material
{
	int				type;
	t_color3		rgb;
	double			fuzz;
	double			refractive_idx;
	t_info_texture	texture;
};

struct s_info_object_point_light
{
	t_point3	pos;
	double		brightness;
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
	t_vector3		normal;
	double			radius;
	t_info_material	material;
};

struct s_info_object_tube
{
	t_point3		center;
	t_vector3		orient;
	double			radius;
	double			height;
	t_info_material	material;
};

struct s_info_object_cylinder
{
	t_info_object_disk	disk[2];
	t_info_object_tube	tube;
	t_info_material		material;
};

struct s_info_object_cone_lateral
{
	t_point3			center;
	t_vector3			orient;
	double				radius;
	double				height;
	t_info_material		material;
};

struct s_info_object_cone
{
	t_info_object_disk			disk;
	t_info_object_cone_lateral	lateral;
	t_info_material				material;
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