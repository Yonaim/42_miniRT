#include "dynamic_arr_internal.h"

/**
 * Clears all the contents in the dynamic array. 
 * It deallocates the pointer array allocation in the dynamic array and
 * initializes all values to 0 or NULL. 
*/
void	clear_dynamic_arr(t_dynamic_arr *arr)
{
	int	i;

	i = 0;
	while (i < arr->cnt)
	{
		free(arr->data[i]);
		i++;
	}
	free(arr->data);
	arr->data = NULL;
	arr->cap = 0;
	arr->cnt = 0;
}

/**
 * Clears all the contents in the dynamic array by calling flush_dynamic_arr
 * and deallocates the dynamic array pointer itself.
*/
void	destroy_dynamic_arr(t_dynamic_arr *arr)
{
	flush_dynamic_arr(arr);
	free(arr);
}
