/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_lateral_hit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:19:21 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/09 09:26:06 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object_internal_bonus.h"

static bool	solve_cone_lateral_intersection_equation(
				double root[2], const t_object_cone_lateral *cl, t_ray *ray);
static bool	is_cone_lateral_sol_in_range(
				double sol,
				const t_object_cone_lateral *cl,
				t_ray *ray, t_hit_record *h_rec);
static void	set_cone_lateral_face_normal(
				t_vector3 *ap,
				const t_object_cone_lateral *cl,
				t_ray *ray, t_hit_record *h_rec);

bool	hit_cone_lateral(
		t_object *self, t_ray *ray, t_hit_record *h_rec, double t_max)
{
	const t_object_cone_lateral	*cl = (t_object_cone_lateral *)self;
	double						root[2];

	if (solve_cone_lateral_intersection_equation(root, cl, ray) == false)
		return (false);
	if (is_num_in_range(root[0], T_MINIMUM, t_max)
		&& (is_cone_lateral_sol_in_range(root[0], cl, ray, h_rec) == true))
		return (true);
	if (is_num_in_range(root[1], T_MINIMUM, t_max)
		&& (is_cone_lateral_sol_in_range(root[1], cl, ray, h_rec) == true))
		return (true);
	return (false);
}

static bool	solve_cone_lateral_intersection_equation(
			double root[2], const t_object_cone_lateral *cl, t_ray *ray)
{
	const t_vector3	ao = v3_sub(ray->origin, cl->apex);
	const double	dir_dot_opp = v3_dot(ray->dir, cl->opposite_orient);
	const double	ao_dot_opp = v3_dot(ao, cl->opposite_orient);
	const double	coeff[3] = {
		len_sqr_v3(ray->dir) - cl->const_m * pow(dir_dot_opp, 2),
		v3_dot(ao, ray->dir) - cl->const_m * dir_dot_opp * ao_dot_opp,
		len_sqr_v3(ao) - cl->const_m * pow(ao_dot_opp, 2)
	};

	if (fabs(coeff[A]) < EPSILON)
		return (false);
	if (solve_quadratic_half_b(coeff[A], coeff[B], coeff[C], root) == false)
		return (false);
	return (true);
}

static bool	is_cone_lateral_sol_in_range(
			double sol,
			const t_object_cone_lateral *cl, t_ray *ray, t_hit_record *h_rec)
{
	t_vector3	ap;
	double		depth_from_apex;

	h_rec->t = sol;
	h_rec->p = ray_at(ray, h_rec->t);
	h_rec->material = cl->material;
	ap = v3_sub(h_rec->p, cl->apex);
	depth_from_apex = v3_dot(ap, cl->opposite_orient);
	if (depth_from_apex < 0 || depth_from_apex > cl->height)
		return (false);
	set_cone_lateral_face_normal(&ap, cl, ray, h_rec);
	return (true);
}

static void	set_cone_lateral_face_normal(
			t_vector3 *ap,
			const t_object_cone_lateral *cl,
			t_ray *ray, t_hit_record *h_rec)
{
	const double	aq_len = sqrt(len_sqr_v3(*ap) + cl->const_m);
	const t_vector3	aq = v3_mul(cl->opposite_orient, aq_len);

	h_rec->normal = v3_sub(*ap, aq);
	h_rec->normal = v3_normalize(h_rec->normal);
	set_face_normal(h_rec, ray, h_rec->normal);
}
