#ifndef PARSER_H
# define PARSER_H

// standard library
# include <math.h>
# include <fcntl.h>
// extra
# include "constants.h"
# include "handle_error.h"
# include "typedef.h"
// structures
# include "s_minirt.h"
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

# include "s_token.h"
# include "s_info_element.h"

enum e_rgb
{
	R,
	G,
	B
};

# define ELEMENT_COUNT					ELEMENT_NONE

# define IDETIFIER_ELEMENT_CAMERA		"C"
# define IDETIFIER_ELEMENT_AMBIENT		"A"
# define IDETIFIER_ELEMENT_LIGHT		"L"
# define IDETIFIER_ELEMENT_SPHERE		"sp"
# define IDETIFIER_ELEMENT_PLANE		"pl"
# define IDETIFIER_ELEMENT_CYLINDER		"cy"
# define IDETIFIER_ELEMENT_CONE			"co"
# define IDETIFIER_ELEMENT_BOX			"bo"

# define IDETIFIER_MATERIAL_LAMBERTIAL	"lam"
# define IDETIFIER_MATERIAL_METAL		"met"
# define IDETIFIER_MATERIAL_DIELECTRIC	"die"
# define IDETIFIER_MATERIAL_EMMISIVE	"emm"
# define IDETIFIER_MATERIAL_RANDOM		"rand"

# define IDETIFIER_TEXTURE_SOLID		"sol"
# define IDETIFIER_TEXTURE_CHECKER		"che"
# define IDETIFIER_TEXTURE_IMAGE		"img"

typedef int	(*t_get_info)(t_token *tokens, void *info);

t_token	*tokenize(char *line);
int		get_token_type(const char *input);
int		length_of_word(const char *line);
int		length_of_number(const char *line);

int		get_element_type(t_token *token);
int		get_material_type(t_token *token);
int		get_texture_type(t_token *token);

int		get_info_ambient(t_token *tokens);
int		get_info_camera(t_token *tokens);
int		get_info_light(t_token *tokens);
int		get_info_plane(t_token *tokens);
int		get_info_sphere(t_token *tokens);
int		get_info_cylinder(t_token *tokens);
int		get_info_cone(t_token *tokens);

#endif
