#ifndef PARSE_INTERNAL_H
# define PARSE_INTERNAL_H

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
# include "object.h"
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

# define IDENTIFIER_ELEMENT_CAMERA			"C"
# define IDENTIFIER_ELEMENT_AMBIENT			"A"
# define IDENTIFIER_ELEMENT_LIGHT			"ptl"
# define IDENTIFIER_ELEMENT_SPHERE			"sp"
# define IDENTIFIER_ELEMENT_PLANE			"pl"
# define IDENTIFIER_ELEMENT_CYLINDER		"cy"
# define IDENTIFIER_ELEMENT_CONE			"co"
# define IDENTIFIER_ELEMENT_BOX				"bo"
# define IDENTIFIER_ELEMENT_DISK			"di"
# define IDENTIFIER_ELEMENT_TUBE			"tu"
# define IDENTIFIER_ELEMENT_CONE_LATERAL	"cl"

# define IDENTIFIER_MATERIAL_LAMBERTIAL		"lam"
# define IDENTIFIER_MATERIAL_METAL			"met"
# define IDENTIFIER_MATERIAL_DIELECTRIC		"die"
# define IDENTIFIER_MATERIAL_EMMISIVE		"emm"
# define IDENTIFIER_MATERIAL_RANDOM			"rand"

# define IDENTIFIER_TEXTURE_SOLID			"sol"
# define IDENTIFIER_TEXTURE_CHECKER			"che"
# define IDENTIFIER_TEXTURE_IMAGE			"img"

t_token_arr		*tokenize(char *line);
int				get_token_type(const char *str);
int				length_of_word(const char *line);
int				length_of_number(const char *line);

int				get_element_type(const char *str);
int				get_material_type(const char *str);
int				get_texture_type(const char *str);

t_info			*get_info_ambient(const t_token_arr *tokens);
t_info			*get_info_camera(const t_token_arr *tokens);
t_info			*get_info_point_light(const t_token_arr *tokens);
t_info			*get_info_plane(const t_token_arr *tokens);
t_info			*get_info_sphere(const t_token_arr *tokens);
t_info			*get_info_tube(const t_token_arr *tokens);
t_info			*get_info_disk(const t_token_arr *tokens);
t_info			*get_info_cylinder(const t_token_arr *tokens);
t_info			*get_info_cone(const t_token_arr *tokens);
t_info			*get_info_cone_lateral(const t_token_arr *tokens);
t_info			*get_info_box(const t_token_arr *tokens);

bool			is_ambient_line(const t_token_arr *tokens);
bool			is_camera_line(const t_token_arr *tokens);
bool			is_point_light_line(const t_token_arr *tokens);
bool			is_plane_line(const t_token_arr *tokens);
bool			is_sphere_line(const t_token_arr *tokens);
bool			is_tube_line(const t_token_arr *tokens);
bool			is_disk_line(const t_token_arr *tokens);
bool			is_cylinder_line(const t_token_arr *tokens);
bool			is_cone_line(const t_token_arr *tokens);
bool			is_cone_lateral_line(const t_token_arr *tokens);
bool			is_box_line(const t_token_arr *tokens);

int				put_ambient_to_scene(t_info *info, t_scene *scene);
int				put_camera_to_scene(t_info *info, t_scene *scene);

int				put_point_light_to_scene(t_info *info, t_scene *scene);
int				put_sphere_to_scene(t_info *info, t_scene *scene);
int				put_disk_to_scene(t_info *info, t_scene *scene);
int				put_tube_to_scene(t_info *info, t_scene *scene);
int				put_cylinder_to_scene(t_info *info, t_scene *scene);
int				put_cone_lateral_to_scene(t_info *info, t_scene *scene);
int				put_cone_to_scene(t_info *info, t_scene *scene);
int				put_plane_to_scene(t_info *info, t_scene *scene);
int				put_box_to_scene(t_info *info, t_scene *scene);

bool			is_valid_formatted_line(const char *elem_id, \
				bool is_solid_elem, const t_token_arr *tokens, const int *form);
bool			is_space(char c);
bool			is_number_str(char *s);
bool			is_identifier_str(char *s);

bool			is_must_be_one_element_type(int type);
bool			is_must_be_elements_exist(bool elem_exist[]);
t_token			*nth_token(const t_token_arr *tokens, int nth);
double			ft_atof(char *str);

t_vector3		parse_vector3(const t_token_arr *tokens, int *offset);
double			parse_number(const t_token_arr *tokens, int *offset);

bool			is_color3_in_255(const t_color3 *c);
bool			is_normalized_vec3(const t_vector3 *v);
bool			is_valid_material(const t_token_arr *tokens, int offset);

t_info_material	get_info_material(const t_token_arr *tokens, int offset);
t_info_texture	get_info_texture(const t_token_arr *tokens, int offset);

bool			is_valid_material_default(\
										const t_token_arr *tokens, int offset);
bool			is_valid_material_random(\
										const t_token_arr *tokens, int offset);
bool			is_valid_material_lambertian(\
										const t_token_arr *tokens, int offset);
bool			is_valid_material_metal(\
										const t_token_arr *tokens, int offset);
bool			is_valid_material_dielectric(\
										const t_token_arr *tokens, int offset);
bool			is_valid_material_emmisive(\
										const t_token_arr *tokens, int offset);

#endif
