#include "dynamic_arr_internal.h"

/**
 * It allocates an array of void pointers which is a member of 
 * the t_dynamic_arr structure with a size of cap, 
 * which is given as an argument to the function. 
 * Then it initializes all elements of the array to NULL and
 * other member variables to proper values.
*/
int	init_dynamic_arr(t_dynamic_arr *darr, int cap)
{
	darr->data = calloc(cap, sizeof(void *));
	if (darr->data == NULL)
		return (FAILURE);
	darr->cap = cap;
	darr->cnt = 0;
	return (SUCCESS);
}

/**
 * It allocate memory for new t_dynamic_arr structure.
 * Also, it allocates an array of void pointers which is a member of 
 * the t_dynamic_arr structure with a size of cap, 
 * which is given as an argument to the function. 
 * Then it initializes all elements of the array to NULL and
 * other member variables to proper values.
*/
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
