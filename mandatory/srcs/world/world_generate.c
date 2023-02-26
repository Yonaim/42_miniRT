#include "world_internal.h"

t_error	init_world(t_world *world, int cap)
{
	if (init_object_arr(&world->objects, cap) == ERROR)
		return (ERROR);
	world->background_color = BACKGROUND_COLOR;
	return (ERROR_NONE);
}

void	flush_world(t_world *world)
{
	flush_object_arr(&world->objects);

}
