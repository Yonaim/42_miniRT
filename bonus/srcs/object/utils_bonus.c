/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:18:43 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/14 10:35:11 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"
#include "s_hit_record_bonus.h"
#include "s_ray_bonus.h"
#include "typedef_bonus.h"

/**
 * Compare the direction of the incident ray with
 * the direction of the outward normal vector at the hit point and record it.
 * 
 * In hit record, these are recorded.
 * 	- whether or not it is opposed (= is ray from in front of face)
 * 	- the direction of the appropriate normal vector
*/
void	set_face_normal(
		t_hit_record *h_rec, t_ray *in_ray, t_vector3 outward_normal)
{
	if (v3_dot(in_ray->dir, outward_normal) < 0)
	{
		h_rec->opposed = true;
		h_rec->normal = outward_normal;
	}
	else
	{
		h_rec->opposed = false;
		h_rec->normal = v3_mul(outward_normal, -1);
	}
}

bool	determine_t(double *t, double root[2], double t_min, double t_max)
{
	if (is_num_in_range(root[0], t_min, t_max))
		*t = root[0];
	else if (is_num_in_range(root[1], t_min, t_max))
		*t = root[1];
	else
		return (false);
	return (true);
}

void	swap_double_value(double *num1, double *num2)
{
	const double	tmp = *num1;

	*num1 = *num2;
	*num2 = tmp;
}
