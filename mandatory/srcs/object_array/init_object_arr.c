#include "object_arr_internal.h"

int	init_object_arr(t_object_arr *objects, int cap)
{
	if (init_dynamic_arr(objects, cap) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
