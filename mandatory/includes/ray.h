/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:19:21 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/05 20:19:21 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "typedef.h"

// ray constructor
t_ray		ray(t_point3 origin, t_vector3 dir);

// where the ray points at
t_point3	ray_at(t_ray *ray, double t);

// primary ray
t_ray		primary_ray(t_camera *cam, double u, double v);

// scattered vectors
t_vector3	reflected_vector(t_vector3 i, t_vector3 n);
t_vector3	refracted_vector(t_vector3 i, t_vector3 n, double idx_ratio);

// scattered rays
t_ray		reflected_ray(t_vector3 in_dir, t_hit_record *rec, double fuzz);
t_ray		refracted_ray(
				t_vector3 in_dir, t_hit_record *rec, double idx_ratio);
t_ray		diffused_ray(t_hit_record *rec);

#endif