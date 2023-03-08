#ifndef TYPEDEF_H
# define TYPEDEF_H

# include "libmath.h"

// minirt
typedef struct s_render_status				t_render_status;
typedef struct s_minirt						t_minirt;

// mlx
typedef struct s_image						t_image;
typedef struct s_mlx						t_mlx;

// scene
typedef struct s_scene						t_scene;

// info
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
typedef struct s_info_object_rectangle		t_info_object_rectangle;
typedef struct s_info_object_xy_rectangle	t_info_object_xy_rectangle;
typedef struct s_info_object_xz_rectangle	t_info_object_xz_rectangle;
typedef struct s_info_object_yz_rectangle	t_info_object_yz_rectangle;
typedef struct s_info_object_box			t_info_object_box;

// scatter record
typedef struct s_scatter_record				t_scatter_record;

// ray
typedef struct s_ray						t_ray;

// camera
typedef struct s_viewport					t_viewport;
typedef struct s_basis_vector				t_basis_vector;
typedef struct s_focus_plane				t_focus_plane;
typedef struct s_camera						t_camera;

// world
typedef struct s_world						t_world;

// dynamic array
typedef struct s_dynamic_arr				t_dynamic_arr;
typedef struct s_dynamic_arr				t_object_arr;
typedef struct s_dynamic_arr				t_token_arr;
typedef struct s_dynamic_arr				t_info_arr;

// object
typedef struct s_object						t_object;
typedef struct s_object_point_light			t_object_point_light;
typedef struct s_object_sphere				t_object_sphere;
typedef struct s_object_disk				t_object_disk;
typedef struct s_object_tube				t_object_tube;
typedef struct s_object_cylinder			t_object_cylinder;
typedef struct s_object_plane				t_object_plane;
typedef struct s_object_cone_lateral		t_object_cone_lateral;
typedef struct s_object_cone				t_object_cone;
typedef struct s_object_xy_rectangle		t_object_xy_rectangle;
typedef struct s_object_xz_rectangle		t_object_xz_rectangle;
typedef struct s_object_yz_rectangle		t_object_yz_rectangle;
typedef struct s_object_box					t_object_box;

// texture
typedef struct s_texture					t_texture;
typedef struct s_texture_solid				t_texture_solid;
typedef struct s_texture_checker			t_texture_checker;
typedef struct s_texture_image				t_texture_image;

// material
typedef struct s_material					t_material;
typedef struct s_material_lambertian		t_material_lambertian;
typedef struct s_material_metal				t_material_metal;
typedef struct s_material_dielectric		t_material_dielectric;
typedef struct s_material_emmisive			t_material_emmisive;

// hit record
typedef struct s_hit_record					t_hit_record;

// pdf
typedef struct s_pdf						t_pdf;

// color
typedef t_vector3							t_color3;

// texture 
typedef t_color3							(*t_get_texture_value)(\
												t_texture *texture, \
												double u, \
												double v, \
												t_point3 p);

// material	
typedef bool								(*t_scatter)(\
													t_material *self, \
													t_ray *in, \
													t_hit_record *h_rec, \
													t_scatter_record *s_rec);

typedef t_color3							(*t_emit)(\
												t_material *self, \
												double u, \
												double v, \
												t_point3 p);

// object
typedef bool								(*t_hit_object)(\
												t_object *self, \
												t_ray *ray, \
												t_hit_record *h_rec, \
												double t_max);

typedef int									(*t_get_object_type)(void);

typedef double								(*t_scattering_pdf)(\
												t_material *self,\
												t_ray *in_ray, \
												t_hit_record *h_rec, \
												t_scatter_record *s_rec);

typedef void								(*t_destroy_object)(\
												t_object *object);
typedef void								(*t_destroy_material)(\
												t_material *material);
typedef void								(*t_destroy_texture)(\
												t_texture *texture);

typedef t_info								*(*t_get_info_element)(\
											const t_token_arr *tokens);
typedef int									(*t_get_identifier_type)(\
											const char *s);
typedef bool								(*t_is_element_line)(\
											const t_token_arr *tokens);
typedef bool								(*t_is_valid_material)(\
										const t_token_arr *tokens, int offset);
typedef int									(*t_put_element)\
											(t_info *info, t_scene *scene);

#endif
