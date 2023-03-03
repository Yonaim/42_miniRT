#include "object_arr_internal.h"

int	add_object(t_object_arr *object_arr, t_object *object)
{
	if (object == NULL)
		return (FAILURE);
	if (push_back_dynamic_arr(object_arr, object) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	add_n_objects(t_object_arr *object_arr, t_object **objects, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (add_object(object_arr, objects[i]) == FAILURE)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
