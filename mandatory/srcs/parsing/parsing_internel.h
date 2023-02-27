
#ifndef PARSING_INTERNEL_H
# define PARSING_INTERNEL_H

# include "libft.h"
# include "constants.h"

// structure definition
# include "s_scene.h"
# include "s_object.h"
# include "s_dynamic_arr.h"
# include "s_material.h"
# include "s_texture.h"
# include "s_info_element.h"

// declaration
# include "object.h"
# include "object_arr.h"
# include "material.h"
# include "texture.h"

// standard library
# include <stdio.h>
# include <fcntl.h>

# define ELEMENT_COUNT	8

enum e_parsing_element_types
{
	NONE,
	AMBIENT,
	CAMERA,
	LIGHT,
	PLANE,
	SPHERE,
	CYLINDER,
	CONE
};

enum e_rgb
{
	R,
	G,
	B
};

typedef struct s_parsing_info_object_cylinder	t_parsing_info_object_cylinder;
typedef struct s_parsing_info_object_cone		t_parsing_info_object_cone;

struct s_parsing_info_object_cylinder
{
	t_point3	center;
	t_vector3	orient;
	double		diameter;
	double		height;
	t_vector3	rgb;
};

struct s_parsing_info_object_cone
{
	t_point3	center;
	t_vector3	orient;
	double		diameter;
	double		height;
	t_vector3	rgb;
};

typedef int										(*t_parse_element)(
													t_scene *scene, char *str);

// parse element
int			parse_element_ambient(t_scene *scene, char *str);
int			parse_element_camera(t_scene *scene, char *str);
int			parse_element_point_light(t_scene *scene, char *str);
int			parse_element_plane(t_scene *scene, char *str);
int			parse_element_sphere(t_scene *scene, char *str);
int			parse_element_cylinder(t_scene *scene, char *str);
int			parse_element_cone(t_scene *scene, char *str);

// build
int			build_element_cone(
				t_object_arr *objects,
				t_parsing_info_object_cone *co_parsing_info);
int			build_element_cylinder(
				t_object_arr *objects,
				t_parsing_info_object_cylinder *cy_parsing_info);
int			build_element_point_light(
				t_object_arr *objects,
				t_point3 *pos, double *brightness, t_vector3 *rgb);
int			build_element_plane(
				t_object_arr *objects,
				t_point3 *pos, t_vector3 *normal, t_vector3 *rgb);
int			build_element_sphere(
				t_object_arr *objects,
				t_point3 *pos, double *diameter, t_vector3 *rgb);

// parse value
int			parse_integer(char **str);
double		parse_double(char **str);
t_vector3	parse_vector3(char **str);

// skip
void		skip_char(char **str, char c);
void		skip_non_char(char **str, char c);
void		skip_until_next_value(char **str);

// check range of value
bool		is_num_in_range(double num, double min, double max);
bool		is_vec3_in_range(t_vector3 vec3, double min, double max);

// atof
double		ft_atof(char *str);

#endif