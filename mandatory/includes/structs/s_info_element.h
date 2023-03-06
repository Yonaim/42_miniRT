#ifndef S_INFO_ELEMENT_H
# define S_INFO_ELEMENT_H

# include "typedef.h"
# include "color.h"

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
	ELEMENT_CONE_LATERAL,
	ELEMENT_CONE,
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
};

struct s_info_object_plane
{
	t_point3		point;
	t_vector3		normal;
	t_info_material	material;
};

enum e_axis_aligned_type
{
	XY,
	XZ,
	YZ
};

struct s_info_object_rectangle
{
	int				type;
	double			range_1[2];
	double			range_2[2];
	double			const_k;
	t_info_material	material;
};

struct s_info_object_xy_rectangle
{
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			z;
	t_info_material	material;
};

struct s_info_object_xz_rectangle
{
	double			x1;
	double			x2;
	double			z1;
	double			z2;
	double			y;
	t_info_material	material;
};

struct s_info_object_yz_rectangle
{
	double			y1;
	double			y2;
	double			z1;
	double			z2;
	double			x;
	t_info_material	material;
};

struct s_info_object_box
{
	t_point3		p_end1;
	t_point3		p_end2;
	t_info_material	material;
};


#endif
