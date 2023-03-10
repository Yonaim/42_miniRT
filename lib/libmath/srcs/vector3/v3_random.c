/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:40:42 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/09 04:04:38 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"
#include "random.h"

t_vector3	v3_random(double min, double max)
{
	return (vector3(random_double_range(min, max), \
				random_double_range(min, max), \
				random_double_range(min, max)));
}

t_vector3	v3_random_in_unit_sphere(void)
{
	t_vector3	random_point;

	while (1)
	{
		random_point = v3_random(-1, 1);
		if (len_sqr_v3(random_point) >= 1)
			continue ;
		return (random_point);
	}
}

t_vector3	v3_random_on_unit_sphere(void)
{
	return (v3_normalize(v3_random_in_unit_sphere()));
}

t_vector3	v3_random_in_unit_disk(void)
{
	t_vector3	random;

	while (1)
	{
		random = vector3(\
			random_double_range(-1, 1), random_double_range(-1, 1), 0);
		if (len_sqr_v3(random) >= 1)
			continue ;
		return (random);
	}
}

t_vector3	v3_random_on_unit_disk(void)
{
	return (v3_normalize(v3_random_in_unit_disk()));
}
