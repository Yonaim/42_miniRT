/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_dynamic_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:19:21 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/09 04:14:12 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynamic_arr_internal_bonus.h"

/**
 * It allocate memory for new s_dynamic_arr structure.
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
