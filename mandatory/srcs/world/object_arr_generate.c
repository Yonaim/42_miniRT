#include "object_arr_internal.h"

t_error	init_object_arr(t_object_arr *objects, int cap)
{
	objects->arr = malloc(sizeof(t_object *) * cap);
	if (objects->arr == NULL)
		return (ERROR);
	objects->cap = cap;
	objects->cnt = 0;
	return (ERROR_NONE);
}

void	flush_object_arr(t_object_arr *objects)
{
	int	i;

	i = 0;
	while (i < objects->cnt)
	{
		objects->arr[i]->destroy(objects->arr[i]);
		++i;
	}
	free(objects->arr);
	objects->arr = NULL;
	objects->cap = 0;
	objects->cnt = 0;
}

