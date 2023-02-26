#ifndef OBJECT_H
# define OBJECT_H

# include "typedef.h"

t_object	*new_sphere(t_point3 center, double radius, t_material *material);
t_object	*new_cylinder(\
					t_point3 pos, t_vector3 orient, \
					double radius, double height, t_material *material);
t_object	*new_plane(t_point3 pos, t_vector3 normal, t_material *material);
t_object	*new_light(t_point3 pos, t_material *material);
t_object	*new_xy_rectangle(\
						const double x[2], const double y[2], const double k, \
						t_material *material);
t_object	*new_xz_rectangle(\
						 const double x[2], const double z[2], const double k, \
						t_material *material);
t_object	*new_yz_rectangle(\
						 const double y[2], const double z[2], const double k, \
						t_material *material);

#endif