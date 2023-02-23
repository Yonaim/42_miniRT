
#ifndef PARSING_INTERNEL_H
# define PARSING_INTERNEL_H

# include "libft.h"
# include "constants.h"
# include "s_scene.h"
# include "s_object.h"
# include "object.h"
# include <stdio.h>
# include <fcntl.h>

enum e_element_types
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

typedef int	(*t_parse_element)(t_ray_tracing *rt, char *str);

// parse element
int			parse_element_ambient(t_ray_tracing *rt, char *str);
int			parse_element_camera(t_ray_tracing *rt, char *str);
int			parse_element_light(t_ray_tracing *rt, char *str);
int			parse_element_plane(t_ray_tracing *rt, char *str);
int			parse_element_sphere(t_ray_tracing *rt, char *str);
int			parse_element_cylinder(t_ray_tracing *rt, char *str);

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