#ifndef TYPEDEF_H
# define TYPEDEF_H

# include "libmath.h"

// mlx
typedef struct s_image					t_image;
typedef struct s_mlx					t_mlx;

// scene
typedef struct s_scene					t_scene;

// ray
typedef struct s_ray					t_ray;

// camera
typedef struct s_viewport				t_viewport;
typedef struct s_base_vector			t_base_vector;
typedef struct s_focus_plane			t_focus_plane;
typedef struct s_camera					t_camera;

// world
typedef struct s_world					t_world;

// object
typedef struct s_object					t_object;
typedef struct s_object_point_light		t_object_point_light;
typedef struct s_object_sphere			t_object_sphere;
typedef struct s_object_disk			t_object_disk;
typedef struct s_object_cylinder		t_object_cylinder;
typedef struct s_object_plane			t_object_plane;

// material
typedef struct s_material				t_material;
typedef struct s_material_lambertian	t_material_lambertian;
typedef struct s_material_metal			t_material_metal;
typedef struct s_material_dielectric	t_material_dielectric;
typedef struct s_material_emmisive		t_material_emmisive;

// hit record
typedef struct s_hit_record				t_hit_record;

// scatter record
typedef struct s_scatter_record			t_scatter_record;

// pdf
typedef struct s_pdf					t_pdf;

// color
typedef t_vector3						t_color3;

typedef bool							(*t_scatter)(\
													t_material *self, \
													t_ray *in, \
													t_hit_record *h_rec, \
													t_scatter_record *s_rec);

typedef bool							(*t_hit)(\
												t_object *self, \
												t_ray *ray, \
												t_hit_record *h_rec, \
												double t_max);

#endif
