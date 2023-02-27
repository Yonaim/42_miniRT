#include "object_arr_internal.h"

static int	_grow_object_arr(t_object_arr *objects)
{
	const int	new_cap = objects->cap * 2;
	t_object	**new_objects;

	new_objects = malloc(sizeof(t_object *) * new_cap);
	if (new_objects == NULL)
		return (FAILURE);
	ft_memcpy(new_objects, objects->arr, sizeof(t_object *) * objects->cnt);
	objects->cap = new_cap;
	free(objects->arr);
	objects->arr = new_objects;
	return (SUCCESS);
}

int	add_object(t_object_arr *objects, t_object *object)
{
	if (objects->cnt == objects->cap
		&& _grow_object_arr(objects) == FAILURE)
		return (FAILURE);
	objects->arr[objects->cnt] = object;
	objects->cnt++;
	return (SUCCESS);
}
