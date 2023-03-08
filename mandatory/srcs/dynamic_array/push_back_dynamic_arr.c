/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_dynamic_arr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:19:21 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/05 20:20:59 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/**
 * The push_back_dynamic_arr function adds an element to the end of the array 
 * stored in the t_dynamic_arr structure pointed to by the darr argument.
 * If the array is full, it increases its capacity by calling _grow_dynamic_arr
 * function internally.
*/
int	push_back_dynamic_arr(t_dynamic_arr *darr, void *data)
{
	if (darr->cnt == darr->cap
		&& _grow_dynamic_arr(darr) == FAILURE)
		return (FAILURE);
	darr->data[darr->cnt] = data;
	darr->cnt++;
	return (SUCCESS);
}
