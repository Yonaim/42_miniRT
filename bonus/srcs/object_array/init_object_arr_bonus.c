/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:18:52 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/05 20:18:52 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object_arr_internal_bonus.h"

int	init_object_arr(t_object_arr *objects, int cap)
{
	if (init_dynamic_arr(objects, cap) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
