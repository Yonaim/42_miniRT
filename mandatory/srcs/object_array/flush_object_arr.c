#include "object_arr_internal.h"

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
