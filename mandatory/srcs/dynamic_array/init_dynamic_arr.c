/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dynamic_arr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 04:14:17 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/09 04:14:17 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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