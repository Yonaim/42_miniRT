#include "object_internal.h"

t_object	*new_tube(t_point3 center, t_vector3 orient, \
							double radius, double height, t_color3 rgb);

bool		hit_tube(t_object *self, t_ray *ray, \
						t_hit_record *h_rec, double t_max);