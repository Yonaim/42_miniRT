#include "dynamic_arr_internal.h"

static int	_grow_dynamic_arr(t_dynamic_arr *arr)
{
	const int	new_cap = arr->cap * 2;
	void		**new_arr;

	new_arr = malloc(sizeof(void *) * new_cap);
	if (new_arr == NULL)
		return (FAILURE);
	ft_memcpy(new_arr, arr->data, sizeof(void *) * arr->cnt);
	arr->cap = new_cap;
	free(arr->data);
	arr->data = new_arr;
	return (SUCCESS);
}

int	darr_push_back(t_dynamic_arr *darr, void *data)
{
	if (darr->cnt == darr->cap
		&& _grow_dynamic_arr(darr) == FAILURE)
		return (FAILURE);
	darr->data[darr->cnt] = data;
	darr->cnt++;
	return (SUCCESS);
}
