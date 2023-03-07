#include "object_arr_internal.h"

t_object	*get_object(t_object_arr *object_arr, int idx)
{
	return ((t_object*)(object_arr->data[idx]));
}
