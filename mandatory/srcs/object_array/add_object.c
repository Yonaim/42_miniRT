#include "object_arr_internal.h"

int	add_object(t_object_arr *objects, t_object *object)
{
	if (object == NULL)
		return (FAILURE);
	if (push_back_dynamic_arr(objects, object) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	add_object_to_world(t_world *world, t_object *object)
{
	if (object->is_light == true
		&& push_back_dynamic_arr(&world->lights, object) == FAILURE)
		return (FAILURE);
	if (push_back_dynamic_arr(&world->objects, object) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
