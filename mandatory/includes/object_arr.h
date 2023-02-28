#ifndef OBJECT_ARR_H
# define OBJECT_ARR_H

# include "typedef.h"

int		init_object_arr(t_object_arr *objects, int cap);
void	flush_object_arr(t_object_arr *objects);
int		add_object(t_object_arr *objects, t_object *object);
bool	hit_object_arr(\
						t_object_arr *objects, t_ray *ray, \
						t_hit_record *final_rec, double t_max);
bool	hit_object_arr_except_point_light(\
						t_object_arr *objects, t_ray *in_ray, \
						t_hit_record *final_rec, double t_max);

#endif