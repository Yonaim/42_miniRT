#ifndef OBJECT_H
# define OBJECT_H

# include "s_object.h"
# include "s_info_element.h"
# include "s_hit_record.h"

// constructor
t_object	*new_point_light(t_info_object_point_light *ptl_info);
t_object	*new_sphere(t_info_object_sphere *sp_info);
t_object	*new_disk(t_info_object_disk *dk_info);
t_object	*new_tube(t_info_object_tube *tb_info);
t_object	*new_cylinder(t_info_object_cylinder *cy_info);
t_object	*new_plane(t_info_object_plane *pl_info);
t_object	*new_cone(t_info_object_cone *co_info);
t_object	*new_cone_lateral(t_info_object_cone_lateral *lat_info);

// hit check
bool		hit_sphere(
				t_object *self, t_ray *ray, t_hit_record *h_rec, double t_max);
bool		hit_cylinder(
				t_object *self, t_ray *ray, t_hit_record *h_rec, double t_max);
bool		hit_tube(
				t_object *self, t_ray *ray, t_hit_record *h_rec, double t_max);
bool		hit_plane(
				t_object *self, t_ray *ray, t_hit_record *h_rec, double t_max);
bool		hit_disk(
				t_object *self, t_ray *ray, t_hit_record *h_rec, double t_max);
bool		hit_point_light(
				t_object *self, t_ray *ray, t_hit_record *h_rec, double t_max);

#endif