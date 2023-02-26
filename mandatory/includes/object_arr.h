#ifndef OBJECT_ARR_H
# define OBJECT_ARR_H

# include "typedef.h"

t_error	init_object_arr(t_object_arr *objects, int cap);
void	flush_object_arr(t_object_arr *objects);
t_error	add_object(t_object_arr *objects, t_object *object);

#endif