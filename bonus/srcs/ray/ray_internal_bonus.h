/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_internal_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:40:42 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/14 10:35:11 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_INTERNAL_BONUS_H
# define RAY_INTERNAL_BONUS_H

# include <math.h>
# include "libmath.h"
# include "s_ray_bonus.h"
# include "s_camera_bonus.h"
# include "s_hit_record_bonus.h"

// ray constructor
t_ray		ray(t_point3 origin, t_vector3 dir);

// scattered vectors
t_vector3	reflected_vector(t_vector3 in, t_vector3 n);
t_vector3	refracted_vector(t_vector3 in, t_vector3 n, double idx_ratio);
t_vector3	diffused_vector(t_vector3 n);

#endif