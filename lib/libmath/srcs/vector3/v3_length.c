/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_length.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:18:52 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/09 04:04:24 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>
#include "vector3.h"

double	len_v3(t_vector3 v)
{
	return (sqrt((v.x * v.x + v.y * v.y + v.z * v.z)));
}

double	len_sqr_v3(t_vector3 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

bool	is_near_zero(t_vector3 v)
{
	return ((fabs(v.x) < EPSILON) \
			&& (fabs(v.y) < EPSILON) \
			&& (fabs(v.z) < EPSILON));
}

bool	is_len_near_one(t_vector3 v)
{
	const double	len = len_v3(v);

	return (1 - EPSILON <= len && len <= 1 + EPSILON);
}
