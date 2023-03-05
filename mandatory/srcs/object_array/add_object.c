#include "object_arr_internal.h"

int	add_object(t_object_arr *objects, t_object *object)
{
	if (object == NULL)
		return (FAILURE);
	if (push_back_dynamic_arr(objects, object) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
