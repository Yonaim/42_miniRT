
#ifndef PARSING_INTERNEL_H
# define PARSING_INTERNEL_H

# include "libft.h"
# include "constants.h"
# include "s_scene.h"
# include "s_object.h"
# include "s_dynamic_arr.h"
# include "s_material.h"
# include "s_texture.h"
# include "object.h"
# include "object_arr.h"
# include "material.h"
# include "texture.h"
# include <stdio.h>
# include <fcntl.h>

enum e_parsing_element_types
{
	NONE,
	AMBIENT,
	CAMERA,
	LIGHT,
	PLANE,
	SPHERE,
	CYLINDER	
};

enum e_rgb
{
	R,
	G,
	B
};

# define ELEMENT_COUNT	7

typedef int	(*t_parse_element)(t_scene *scene, char *str);

// parse element
int			parse_element_ambient(t_scene *scene, char *str);
int			parse_element_camera(t_scene *scene, char *str);
int			parse_element_point_light(t_scene *scene, char *str);
int			parse_element_plane(t_scene *scene, char *str);
int			parse_element_sphere(t_scene *scene, char *str);
int			parse_element_cylinder(t_scene *scene, char *str);

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

// list
int			add_to_object_list(t_list **object_list, t_object *new_object);

#endif