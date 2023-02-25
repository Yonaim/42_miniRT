#include "world_internal.h"

t_error	init_world(t_world *world, int cap)
{
	world->objects = malloc(sizeof(t_object *) * cap);
	if (!world->objects)
		return (ERROR);
	world->cap = cap;
	world->cnt = 0;
	world->background_color = BACKGROUND_COLOR;
	return (ERROR_NONE);
}

t_world	*new_world(int cap)
{
	t_world	*new;

	new = malloc(sizeof(t_world));
	if (!new)
		return (NULL);
	if (init_world(new, cap) == ERROR)
	{
		free(new);
		return (NULL);
	}
	return (new);
}

void	flush_world(t_world *world)
{
	int	i;

	i = 0;
	while (i < world->cnt)
	{
		free(world->objects[i]->material);
		++i;
	}
	free(world->objects);
	world->objects = NULL;
	world->cap = 0;
	world->cnt = 0;
}

void	destroy_world(t_world **world)
{
	flush_world(*world);
	free(*world);
	*world = NULL;
}
