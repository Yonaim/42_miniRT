/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:40:42 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/09 06:06:08 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_internal.h"

t_ray	ray(t_point3 origin, t_vector3 dir)
{
	t_ray	ray;

	ray.origin = origin;
	ray.dir = v3_normalize(dir);
	return (ray);
}

t_point3	ray_at(t_ray *ray, double t)
{
	return ((t_point3)v3_add(ray->origin, v3_mul(ray->dir, t)));
}
