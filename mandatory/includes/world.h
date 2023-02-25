#ifndef WORLD_H
# define WORLD_H

# include "typedef.h"

t_error	init_world(t_world *world, int cap);
t_world	*new_world(int cap);
void	flush_world(t_world *world);
void	destroy_world(t_world **world);
t_error	add_object(t_world *world, t_object *object);

#endif