#include "object_arr_internal.h"

void	clear_object_arr(t_object_arr *objects)
{
	t_object	*cur_obj;
	int			i;

	i = 0;
	while (i < objects->cnt)
	{
		cur_obj = (t_object *)(objects->data[i]);
		cur_obj->destroy(cur_obj);
		++i;
	}
	free(objects->data);
}
