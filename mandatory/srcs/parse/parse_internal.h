#ifndef PARSER_H
# define PARSER_H

// standard library
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
// extra
# include "libft.h"
# include "constants.h"
# include "handle_error.h"
# include "typedef.h"
// structures
# include "s_scene.h"
# include "s_mlx.h"
# include "s_hit_record.h"
# include "s_scatter_record.h"
# include "s_material.h"
# include "s_object.h"
# include "s_ray.h"
// prototypes
# include "mlx_utils.h"
# include "ray.h"
# include "parsing.h"
# include "camera.h"
# include "object_arr.h"
# include "color.h"
# include "dynamic_arr.h"

# include "s_token.h"
# include "s_info_element.h"

enum e_rgb
{
	R,
	G,
	B
};

# define IDENTIFIER_ELEMENT_CAMERA		"C"
# define IDENTIFIER_ELEMENT_AMBIENT		"A"
# define IDENTIFIER_ELEMENT_LIGHT		"ptl"
# define IDENTIFIER_ELEMENT_SPHERE		"sp"
# define IDENTIFIER_ELEMENT_PLANE		"pl"
# define IDENTIFIER_ELEMENT_CYLINDER	"cy"
# define IDENTIFIER_ELEMENT_CONE		"co"
# define IDENTIFIER_ELEMENT_BOX			"bo"

# define IDENTIFIER_MATERIAL_LAMBERTIAL	"l"
# define IDENTIFIER_MATERIAL_METAL		"m"
# define IDENTIFIER_MATERIAL_DIELECTRIC	"d"
# define IDENTIFIER_MATERIAL_EMMISIVE	"e"
# define IDENTIFIER_MATERIAL_RANDOM		"rand"

# define IDENTIFIER_TEXTURE_SOLID		"s"
# define IDENTIFIER_TEXTURE_CHECKER		"c"
# define IDENTIFIER_TEXTURE_IMAGE		"i"

typedef t_dynamic_arr	t_token_arr;

typedef t_info			*(*t_get_info_element)(t_token *tokens);
typedef int				(*t_get_identifier_type)(const char *s);
typedef	bool	 		(*t_is_element_line)(t_token *tokens);

t_token_arr	*tokenize(char *line);
int			get_token_type(const char *input);
int			length_of_word(const char *line);
int			length_of_number(const char *line);

int			get_element_type(const char *str);
int			get_material_type(const char *str);
int			get_texture_type(const char *str);

t_info		*get_info_ambient(t_token_arr *tokens);
t_info		*get_info_camera(t_token_arr *tokens);
t_info		*get_info_light(t_token_arr *tokens);
t_info		*get_info_plane(t_token_arr *tokens);
t_info		*get_info_sphere(t_token_arr *tokens);
t_info		*get_info_cylinder(t_token_arr *tokens);
t_info		*get_info_cone(t_token_arr *tokens);
t_info		*get_info_box(t_token_arr *tokens);

bool		is_ambient_line(t_token_arr *tokens);
bool		is_camera_line(t_token_arr *tokens);
bool		is_light_line(t_token_arr *tokens);
bool		is_plane_line(t_token_arr *tokens);
bool		is_sphere_line(t_token_arr *tokens);
bool		is_cylinder_line(t_token_arr *tokens);
bool		is_cone_line(t_token_arr *tokens);
bool		is_box_line(t_token_arr *tokens);

bool		is_valid_formatted_line(char *identifier, \
								int *form, t_token_arr *tokens);
bool		is_space(char c);
bool		is_number_str(char *s);
bool		is_identifier_str(char *s);

#endif
