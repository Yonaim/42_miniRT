#include "dynamic_arr_internal.h"

int	init_dynamic_arr(t_dynamic_arr *darr, int cap)
{
	darr->data = malloc(sizeof(void *) * cap);
	if (darr->data == NULL)
		return (FAILURE);
	darr->cap = cap;
	darr->cnt = 0;
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
