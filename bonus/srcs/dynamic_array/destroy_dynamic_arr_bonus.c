/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_dynamic_arr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:19:21 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/05 20:21:41 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynamic_arr_internal_bonus.h"

/**
 * Clears all the contents in the dynamic array. 
 * It deallocates the pointer array allocation in the dynamic array and
 * initializes all values to 0 or NULL. 
*/
void	clear_dynamic_arr(t_dynamic_arr *darr)
{
	int	i;

	i = 0;
	while (i < darr->cnt)
	{
		free(darr->data[i]);
		i++;
	}
	free(darr->data);
	darr->data = NULL;
	darr->cap = 0;
	darr->cnt = 0;
}

/**
 * Clears all the contents in the dynamic array by calling flush_dynamic_arr
 * and deallocates the dynamic array pointer itself.
*/
void	destroy_dynamic_arr(t_dynamic_arr *darr)
{
	clear_dynamic_arr(darr);
	free(darr);
}
