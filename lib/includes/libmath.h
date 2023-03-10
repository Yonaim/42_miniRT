/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmath.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:18:52 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/05 20:18:52 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMATH_H
# define LIBMATH_H

/*-------------- USER DEFINED HEADERS ------------*/

# include "vector3.h"
# include "orthonormal_basis.h"

/*------------- STRUCT DECLARATIONS --------------*/

// vector constructor
t_vector3	vector3(double x, double y, double z);
t_point3	point3(double x, double y, double z);
t_point3	color3(double x, double y, double z);

// basic operator
t_vector3	v3_add(t_vector3 u, t_vector3 v);
t_vector3	v3_sub(t_vector3 u, t_vector3 v);
t_vector3	v3_mul(t_vector3 v, double t);
t_vector3	v3_div(t_vector3 v, double t);

// length utils
double		len_v3(t_vector3 v);
double		len_sqr_v3(t_vector3 v);
bool		is_near_zero(t_vector3 v);
bool		is_len_near_one(t_vector3 v);

// v3_normalize
t_vector3	v3_normalize(t_vector3 v);

// product
double		v3_dot(t_vector3 u, t_vector3 v);
t_vector3	v3_cross(t_vector3 u, t_vector3 v);
t_vector3	v3_comp_wise(t_vector3 u, t_vector3 v);

// random vector
t_vector3	v3_random(double min, double max);
t_vector3	v3_random_in_unit_sphere(void);
t_vector3	v3_random_on_unit_sphere(void);
t_vector3	v3_random_in_unit_disk(void);
t_vector3	v3_random_on_unit_disk(void);

// discriminant
bool		solve_quadratic(double a, double b, double c, double root[2]);
bool		solve_quadratic_half_b(\
							double a, double half_b, double c, double root[2]);

// range
bool		is_num_in_range(double n, double min, double max);
bool		is_vec3_in_range(t_vector3 v, double min, double max);
double		clamp(double x, double min, double max);

// trigonometry
double		degree_to_radian(double degrees);

// random
double		random_double(void);
double		random_double_range(double min, double max);

// orthonormal basis
t_onb		orthonormal_basis(t_vector3 n);
t_vector3	onb_local(t_onb onb, t_vector3 v);

#endif
