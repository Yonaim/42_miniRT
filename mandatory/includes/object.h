#ifndef OBJECT_H
# define OBJECT_H

# include "s_object.h"
# include "s_hit_record.h"

// constructor
t_object	*new_sphere(t_point3 center, double radius, t_material *material);
t_object	*new_cylinder(t_object_tube *tube, t_object_disk *disk[2]);
t_object	*new_plane(t_point3 pos, t_vector3 normal, t_color3 rgb);
t_object	*new_disk(t_point3 center, double radius, \
								t_vector3 normal, t_material *material);
t_object	*new_tube(t_object_disk *disk, t_vector3 orient, \
							double height, t_material *material);
t_object	*new_point_light(t_point3 pos, double ratio, t_color3 rgb);

// hit check
bool		hit_sphere(t_object *self, t_ray *ray, \
						t_hit_record *h_rec, double t_max);
bool		hit_cylinder(t_object *self, t_ray *ray, \
						t_hit_record *h_rec, double t_max);
bool		hit_tube(t_object *self, t_ray *ray, \
						t_hit_record *h_rec, double t_max);
bool		hit_plane(t_object *self, t_ray *ray, \
						t_hit_record *h_rec, double t_max);
bool		hit_disk(t_object *self, t_ray *ray, \
						t_hit_record *h_rec, double t_max);
bool		hit_point_light(t_object *self, t_ray *ray, \
						t_hit_record *h_rec, double t_max);

#endif