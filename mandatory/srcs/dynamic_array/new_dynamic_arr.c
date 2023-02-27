#include "dynamic_arr_internal.h"

int	init_dynamic_arr(t_dynamic_arr *arr, int cap)
{
	arr->data = malloc(sizeof(void*) * cap);
	if (arr->data == NULL)
		return (FAILURE);
	arr->data = cap;
	arr->data = 0;
	return (SUCCESS);
}

t_dynamic_arr	*new_dynamic_arr(int cap)
{
	t_dynamic_arr	*new;

	new = malloc(sizeof(t_dynamic_arr));
	if (new == NULL)
		return (NULL);
	if (init_dynamic_arr(new, cap) == FAILURE)
	{
		free(new);
		return (NULL);
	}
	return (new);
}
