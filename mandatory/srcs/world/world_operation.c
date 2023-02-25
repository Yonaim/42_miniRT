#include "world_internal.h"

static t_error	_grow_world(t_world *world)
{
	const int	new_cap = world->cap * 2;
	t_object	**new_objects;

	new_objects = malloc(sizeof(t_object *) * new_cap);
	if (new_objects == NULL)
		return (ERROR);
	ft_memcpy(new_objects, world->objects, sizeof(t_object *) * world->cnt);
	world->cap = new_cap;
	free(world->objects);
	world->objects = new_objects;
	return (ERROR_NONE);
}

t_error	add_object(t_world *world, t_object *object)
{
	if (world->cnt == world->cap
		&& _grow_world(world) == ERROR)
		return (ERROR);
	world->objects[world->cnt] = object;
	world->cnt++;
	return (ERROR_NONE);
}
