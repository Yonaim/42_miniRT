#include "s_object.h"

t_object	*new_disk(t_point3 center, double radius, t_vector normal, t_color3 rgb);

bool		hit_disk(t_object *self, t_ray *ray, \
						t_hit_record *h_rec, double t_max);