/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scattered_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:19:21 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/09 03:58:05 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_internal_bonus.h"

t_ray	reflected_ray(t_vector3 in_dir, t_hit_record *rec, double fuzz)
{
	const t_vector3	unit_in_dir = v3_normalize(in_dir);
	t_vector3		reflected;

	reflected = reflected_vector(unit_in_dir, rec->normal);
	reflected = v3_add(reflected, v3_mul(v3_random_in_unit_sphere(), fuzz));
	reflected = v3_normalize(reflected);
	return (ray(rec->p, reflected));
}

t_ray	refracted_ray(t_vector3 in_dir, t_hit_record *rec, double idx_ratio)
{
	const t_vector3	unit_in_dir = v3_normalize(in_dir);
	t_vector3		refracted;

	refracted = refracted_vector(unit_in_dir, rec->normal, idx_ratio);
	refracted = v3_normalize(refracted);
	return (ray(rec->p, refracted));
}

t_ray	diffused_ray(t_hit_record *rec)
{
	t_vector3	diffused;

	diffused = diffused_vector(rec->normal);
	diffused = v3_normalize(diffused);
	return (ray(rec->p, diffused));
}
