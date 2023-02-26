#ifndef TYPEDEF_H
# define TYPEDEF_H

# include "libmath.h"

// scene
typedef struct s_scene					t_scene;

// scattered record
typedef struct s_scatter_record			t_scatter_record;

// ray
typedef struct s_ray					t_ray;

// camera
typedef struct s_viewport				t_viewport;
typedef struct s_base_vector			t_base_vector;
typedef struct s_focus_plane			t_focus_plane;
typedef struct s_camera					t_camera;

// world
typedef struct s_object_arr				t_object_arr;
typedef struct s_world					t_world;

// object
typedef struct s_object					t_object;
typedef struct s_object_point_light		t_object_point_light;
typedef struct s_object_sphere			t_object_sphere;
typedef struct s_object_disk			t_object_disk;
typedef struct s_object_cylinder		t_object_cylinder;
typedef struct s_object_plane			t_object_plane;
typedef struct s_object_xy_rectangle	t_object_xy_rectangle;
typedef struct s_object_xz_rectangle	t_object_xz_rectangle;
typedef struct s_object_yz_rectangle	t_object_yz_rectangle;
typedef struct s_object_box				t_object_box;

// material
typedef struct s_material				t_material;
typedef struct s_material_lambertian	t_material_lambertian;
typedef struct s_material_metal			t_material_metal;
typedef struct s_material_dielectric	t_material_dielectric;
typedef struct s_material_emmisive		t_material_emmisive;

// texture
typedef struct s_texture				t_texture;
typedef struct s_texture_solid			t_texture_solid;
typedef struct s_texture_checker		t_texture_checker;
typedef struct s_texture_image			t_texture_image;

// hit record
typedef struct s_hit_record				t_hit_record;

// pdf
typedef struct s_pdf					t_pdf;

// color
typedef t_vector3						t_color3;

// error
typedef enum e_error					t_error;

typedef bool							(*t_scatter)(\
												t_material *self, \
												t_ray *in, \
												t_hit_record *h_rec, \
												t_scatter_record *s_rec);

typedef t_color3						(*t_emit)(\
												t_material *self, \
												double u, \
												double v, \
												t_point3 p);

typedef bool							(*t_hit)(\
												t_object *self, \
												t_ray *ray, \
												t_hit_record *h_rec, \
												double t_max);

typedef t_color3						(*t_get_texture_value)(\
												t_texture *texture, \
												double u, \
												double v, \
												t_point3 p);

typedef void							(*t_destroy_object)(\
												t_object *object);
typedef void							(*t_destroy_material)(\
												t_material *material);
typedef void							(*t_destroy_texture)(\
												t_texture *texture);

#endif
