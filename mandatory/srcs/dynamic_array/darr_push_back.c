#include "dynamic_arr_internal.h"

static int	_grow_dynamic_arr(t_dynamic_arr *darr)
{
	const int	new_cap = darr->cap * 2;
	void		**new_darr;

	new_darr = malloc(sizeof(void *) * new_cap);
	if (new_darr == NULL)
		return (FAILURE);
	ft_memcpy(new_darr, darr->data, sizeof(void *) * darr->cnt);
	darr->cap = new_cap;
	free(darr->data);
	darr->data = new_darr;
	return (SUCCESS);
}

int	push_back_dynamic_arr(t_dynamic_arr *darr, void *data)
{
	if (darr->cnt == darr->cap
		&& _grow_dynamic_arr(darr) == FAILURE)
		return (FAILURE);
	darr->data[darr->cnt] = data;
	darr->cnt++;
	return (SUCCESS);
}
