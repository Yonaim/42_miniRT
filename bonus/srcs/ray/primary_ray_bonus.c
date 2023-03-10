/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primary_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:19:21 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/09 06:36:44 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_internal_bonus.h"

t_ray	primary_ray(t_camera *cam, double u, double v)
{
	t_vector3	random_dist;
	t_vector3	offset;
	t_point3	initial_pt;
	t_point3	terminal_pt;
	t_vector3	direction;

	random_dist = v3_mul(v3_random_in_unit_disk(), cam->lens_radius);
	offset = v3_add(v3_mul(cam->basis.right, random_dist.x), \
					v3_mul(cam->basis.up, random_dist.y));
	initial_pt = v3_add(cam->origin, offset);
	terminal_pt = v3_add(v3_add(cam->focus.bottom_left, \
								v3_mul(cam->focus.horiz, u)), \
						v3_mul(cam->focus.vert, v));
	direction = v3_sub(terminal_pt, initial_pt);
	return (ray(initial_pt, direction));
}
