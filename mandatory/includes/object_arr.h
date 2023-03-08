/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_arr.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:18:43 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/05 21:18:43 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_ARR_H
# define OBJECT_ARR_H

# include "typedef.h"

int		init_object_arr(t_object_arr *objects, int cap);
void	clear_object_arr(t_object_arr *objects);
int		add_object(t_object_arr *objects, t_object *object);
int		add_n_objects(t_object_arr *object_arr, t_object **objects, int n);
bool	hit_object_arr(
			t_object_arr *objects, t_ray *ray,
			t_hit_record *final_rec, double t_max);
bool	hit_object_arr_except_point_light(
			t_object_arr *objects, t_ray *in_ray,
			t_hit_record *final_rec, double t_max);

#endif