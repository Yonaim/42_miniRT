/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_object_arr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:19:21 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/05 20:21:23 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object_arr_internal_bonus.h"

void	clear_object_arr(t_object_arr *objects)
{
	t_object	*cur_obj;
	int			i;

	i = 0;
	while (i < objects->cnt)
	{
		cur_obj = (t_object *)(objects->data[i]);
		cur_obj->destroy(cur_obj);
		++i;
	}
	free(objects->data);
}
