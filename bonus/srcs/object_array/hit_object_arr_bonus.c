/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_object_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:19:21 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/05 20:19:21 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object_arr_internal_bonus.h"

bool	hit_object_arr_except_point_light(
		t_object_arr *objects, t_ray *in_ray,
		t_hit_record *final_rec, double t_max)
{
	bool			is_hit;
	double			closest_t;
	int				i;
	t_object		*cur_obj;
	t_hit_record	cur_rec;

	is_hit = false;
	closest_t = t_max;
	i = 0;
	while (i < objects->cnt)
	{
		cur_obj = (t_object *)objects->data[i];
		if (cur_obj->get_type() != OBJECT_POINT_LIGHT
			&& cur_obj->hit(cur_obj, in_ray, &cur_rec, closest_t) == true)
		{
			is_hit = true;
			*final_rec = cur_rec;
			closest_t = cur_rec.t;
		}
		i++;
	}
	return (is_hit);
}

bool	hit_object_arr(
		t_object_arr *objects, t_ray *in_ray,
		t_hit_record *final_rec, double t_max)
{
	bool			is_hit;
	double			closest_t;
	int				i;
	t_object		*cur_obj;
	t_hit_record	cur_rec;

	is_hit = false;
	closest_t = t_max;
	i = 0;
	while (i < objects->cnt)
	{
		cur_obj = (t_object *)objects->data[i];
		if (cur_obj->hit(cur_obj, in_ray, &cur_rec, closest_t) == true)
		{
			is_hit = true;
			*final_rec = cur_rec;
			closest_t = cur_rec.t;
		}
		i++;
	}
	return (is_hit);
}
