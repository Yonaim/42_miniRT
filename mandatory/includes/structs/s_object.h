/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_object.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:18:43 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/05 21:18:43 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_OBJECT_H
# define S_OBJECT_H

# include <stdbool.h>
# include <stddef.h>
# include "typedef.h"
# include "s_dynamic_arr.h"

enum e_object_type
{
	OBJECT_POINT_LIGHT,
	OBJECT_SPHERE,
	OBJECT_DISK,
	OBJECT_TUBE,
	OBJECT_CYLINDER,
	OBJECT_CONE_LATERAL,
	OBJECT_CONE,
	OBJECT_PLANE,
	OBJECT_XY_RECTANGLE,
	OBJECT_XZ_RECTANGLE,
	OBJECT_YZ_RECTANGLE,
	OBJECT_BOX
};

struct s_object
{
	t_hit_object		hit;
	t_destroy_object	destroy;
	t_get_object_type	get_type;
};

struct s_object_point_light
{
	t_hit_object		hit;
	t_destroy_object	destroy;
	t_get_object_type	get_type;
	t_object			*sphere;
};

struct s_object_sphere
{
	t_hit_object		hit;
	t_destroy_object	destroy;
	t_get_object_type	get_type;
	t_material			*material;
	t_point3			center;
	double				radius;
};

struct s_object_disk
{
	t_hit_object		hit;
	t_destroy_object	destroy;
	t_get_object_type	get_type;
	t_material			*material;
	t_point3			center;
	double				radius;
	t_vector3			normal;
};

struct s_object_tube
{
	t_hit_object		hit;
	t_destroy_object	destroy;
	t_get_object_type	get_type;
	t_material			*material;
	t_point3			center;
	double				radius;
	double				height;
	t_vector3			orient;
};

struct s_object_cylinder
{
	t_hit_object		hit;
	t_destroy_object	destroy;
	t_get_object_type	get_type;
	t_object_arr		faces;
};

struct s_object_cone_lateral
{
	t_hit_object		hit;
	t_destroy_object	destroy;
	t_get_object_type	get_type;
	t_material			*material;
	t_point3			center;
	t_point3			apex;
	t_vector3			orient;
	t_vector3			opposite_orient;
	double				radius;
	double				height;
	double				const_m;
};

struct s_object_cone
{
	t_hit_object		hit;
	t_destroy_object	destroy;
	t_get_object_type	get_type;
	t_object_arr		faces;
};

struct s_object_plane
{
	t_hit_object		hit;
	t_destroy_object	destroy;
	t_get_object_type	get_type;
	t_material			*material;
	t_point3			point;
	t_vector3			normal;
};

struct s_object_xy_rectangle
{
	t_hit_object		hit;
	t_destroy_object	destroy;
	t_get_object_type	get_type;
	t_material			*material;
	double				x1;
	double				x2;
	double				y1;
	double				y2;
	double				z;
};

struct s_object_xz_rectangle
{
	t_hit_object		hit;
	t_destroy_object	destroy;
	t_get_object_type	get_type;
	t_material			*material;
	double				x1;
	double				x2;
	double				z1;
	double				z2;
	double				y;
};

struct s_object_yz_rectangle
{
	t_hit_object		hit;
	t_destroy_object	destroy;
	t_get_object_type	get_type;
	t_material			*material;
	double				y1;
	double				y2;
	double				z1;
	double				z2;
	double				x;
};

struct s_object_box
{	
	t_hit_object		hit;
	t_destroy_object	destroy;
	t_get_object_type	get_type;
	t_point3			p_end1;
	t_point3			p_end2;
	t_object_arr		faces;
};

#endif
