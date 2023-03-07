#ifndef OBJECT_ARR_H
# define OBJECT_ARR_H

# include "typedef.h"

int			init_object_arr(t_object_arr *objects, int cap);
int			init_world(t_world *world, int cap);
void		clear_object_arr(t_object_arr *objects);
t_object	*get_object(t_object_arr *object_arr, int idx);
int			add_object(t_object_arr *objects, t_object *object);
int			add_object_to_world(t_world *world, t_object *object);
bool		hit_object_arr(
				t_object_arr *objects, t_ray *ray,
				t_hit_record *final_rec, double t_max);
bool		hit_object_arr_except_point_light(
				t_object_arr *objects, t_ray *in_ray,
				t_hit_record *final_rec, double t_max);

#endif