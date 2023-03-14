/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:19:21 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/09 03:47:22 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_internal_bonus.h"

static bool	hit_world(
			t_object_arr *objects, t_ray *in_ray,
			t_hit_record *h_rec, int depth)
{
	if (depth == 0)
		return (hit_object_arr_except_point_light(\
										objects, in_ray, h_rec, T_INFINITY));
	else
		return (hit_object_arr(objects, in_ray, h_rec, T_INFINITY));
	return (false);
}

t_color3	traced_color(t_ray *in_ray, t_world *world, int depth)
{
	t_hit_record		h_rec;
	t_scatter_record	s_rec;
	t_material			*material;
	t_color3			emitted;
	t_color3			summed;

	if (depth >= MAX_DEPTH)
		return (color3(0, 0, 0));
	if (hit_world(&world->objects, in_ray, &h_rec, depth) == false)
		return (world->background_color);
	material = h_rec.material;
	emitted = material->emitted(material, h_rec.u, h_rec.v, h_rec.p);
	if (material->scattered(material, in_ray, &h_rec, &s_rec) == false)
		return (emitted);
	summed = v3_comp_wise(\
						traced_color(&s_rec.scattered, world, depth + 1), \
						s_rec.attenuation);
	return (v3_add(summed, emitted));
}
