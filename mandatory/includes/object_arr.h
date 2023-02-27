#ifndef OBJECT_ARR_H
# define OBJECT_ARR_H

# include "typedef.h"

bool	init_object_arr(t_object_arr *objects, int cap);
void	flush_object_arr(t_object_arr *objects);
bool	add_object(t_object_arr *objects, t_object *object);
bool	hit_objects(\
				t_object_arr *objects, \
				t_ray *ray, \
				t_hit_record *final_rec, \
				double t_max);

#endif