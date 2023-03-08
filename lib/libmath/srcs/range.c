/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:18:52 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/05 20:18:52 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "vector3.h"

bool	is_num_in_range(double n, double min, double max)
{
	return (min <= n && n <= max);
}

bool	is_vec3_in_range(t_vector3 v, double min, double max)
{
	return ((min <= v.x && v.x <= max) \
			&& (min <= v.y && v.y <= max) \
			&& (min <= v.z && v.z <= max));
}

double	clamp(double x, double min, double max)
{
	if (x < min)
		return (min);
	if (x > max)
		return (max);
	return (x);
}
