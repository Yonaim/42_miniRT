/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scattered_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:19:21 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/05 20:19:21 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_internal_bonus.h"

static double	reflectance(double cosine, double idx_ratio)
{
	double	r0;

	r0 = (1 - idx_ratio) / (1 + idx_ratio);
	r0 *= r0;
	return (r0 + (1 - r0) * pow(1 - cosine, 5));
}

t_vector3	reflected_vector(t_vector3 in, t_vector3 n)
{
	t_vector3	reflected;

	reflected = v3_sub(in, v3_mul(n, 2 * v3_dot(in, n)));
	return (reflected);
}

t_vector3	refracted_vector(t_vector3 in, t_vector3 n, double idx_ratio)
{
	const double	cos_in = fmin(-v3_dot(in, n), 1);
	const double	sin_in = sqrt(1 - cos_in * cos_in);
	t_vector3		refracted_perp;
	t_vector3		refracted_par;
	t_vector3		refracted;

	if (idx_ratio * sin_in > 1
		|| reflectance(cos_in, idx_ratio) > random_double())
		return (reflected_vector(in, n));
	refracted_perp = v3_mul(v3_add(in, v3_mul(n, cos_in)), idx_ratio);
	refracted_par = v3_mul(n, -sqrt(fabs(1 - len_sqr_v3(refracted_perp))));
	refracted = v3_add(refracted_par, refracted_perp);
	return (refracted);
}

t_vector3	diffused_vector(t_vector3 n)
{
	t_vector3	diffused;

	diffused = v3_add(n, v3_random_on_unit_sphere());
	if (is_near_zero(diffused) == true)
		diffused = n;
	return (diffused);
}
