/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_internal_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:46:12 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/14 10:35:23 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_INTERNAL_BONUS_H
# define OBJECT_INTERNAL_BONUS_H

// standard library
# include <stdlib.h>
# include <math.h>
// library
# include "libft.h"
# include "libmath.h"
// structure and typedefine
# include "s_material_bonus.h"
# include "s_hit_record_bonus.h"
# include "s_object_bonus.h"
# include "s_ray_bonus.h"
# include "s_info_element_bonus.h"
# include "constants_bonus.h"
# include "typedef_bonus.h"
// functions
# include "ray_bonus.h"
# include "texture_bonus.h"
# include "material_bonus.h"
# include "object_arr_bonus.h"

enum	e_equation_coefficient
{
	A,
	B,
	C
};

// Utils
void		set_face_normal(
				t_hit_record *h_rec, t_ray *in_ray, t_vector3 outward_normal);
bool		determine_t(double *t, double root[2], double t_min, double t_max);
void		swap_double_value(double *num1, double *num2);

// Constructor
t_object	*new_sphere(const t_info_object_sphere *sp_info);
t_object	*new_tube(const t_info_object_tube *tb_info);
t_object	*new_disk(const t_info_object_disk *dk_info);
t_object	*new_cone_lateral(const t_info_object_cone_lateral *lat_info);
t_object	*new_xy_rectangle(t_info_object_xy_rectangle *xy_rec_info);
t_object	*new_xz_rectangle(t_info_object_xz_rectangle *xz_rec_info);
t_object	*new_yz_rectangle(t_info_object_yz_rectangle *yz_rec_info);

#endif