#include "object_internal.h"

/*
	TODO: hit 계산 공식 설명문 추가
*/
static bool	solve_cone_lateral_intersection_equation(
				double root[2], const t_object_cone_lateral *lat, t_ray *ray);
static bool	is_cone_lateral_sol_in_range(
				t_vector3 *ap, const t_object_cone_lateral *lat);
static void	set_cone_lateral_face_normal(
				t_vector3 *ap,
				const t_object_cone_lateral *lat,
				t_ray *ray, t_hit_record *h_rec);

bool	hit_cone_lateral(
		t_object *self, t_ray *ray, t_hit_record *h_rec, double t_max)
{
	const t_object_cone_lateral	*lat = (t_object_cone_lateral *)self;
	double						root[2];
	double						t;
	t_vector3					ap;

	if (solve_cone_lateral_intersection_equation(root, lat, ray) == false)
		return (false);
	if (determine_t(&t, root, T_MINIMUM, t_max) == false)
		return (false);
	h_rec->t = t;
	h_rec->p = ray_at(ray, t);
	h_rec->material = lat->material;
	ap = v3_sub(h_rec->p, lat->apex);
	if (is_cone_lateral_sol_in_range(&ap, lat) == false)
		return (false);
	set_cone_lateral_face_normal(&ap, lat, ray, h_rec);
	return (true);
}

static bool	solve_cone_lateral_intersection_equation(
			double root[2], const t_object_cone_lateral *lat, t_ray *ray)
{
	const t_vector3	ao = v3_sub(ray->origin, lat->apex);
	const double	dir_dot_opp = v3_dot(ray->dir, lat->opposite_orient);
	const double	ao_dot_opp = v3_dot(ao, lat->opposite_orient);
	const double	coeff[3] = {
		len_sqr_v3(ray->dir) - lat->const_m * pow(dir_dot_opp, 2),
		v3_dot(ao, ray->dir) - lat->const_m * dir_dot_opp * ao_dot_opp,
		len_sqr_v3(ao) - lat->const_m * pow(ao_dot_opp, 2)
	};

	if (fabs(coeff[A]) < EPSILON)
		return (false);
	if (solve_quadratic_half_b(coeff[A], coeff[B], coeff[C], root) == false)
		return (false);
	return (true);
}

static bool	is_cone_lateral_sol_in_range(
			t_vector3 *ap, const t_object_cone_lateral *lat)
{
	const double	depth_from_apex = v3_dot(*ap, lat->opposite_orient);

	if (depth_from_apex < 0 || depth_from_apex > lat->height)
		return (false);
	return (true);
}

static void	set_cone_lateral_face_normal(
			t_vector3 *ap,
			const t_object_cone_lateral *lat,
			t_ray *ray, t_hit_record *h_rec)
{
	const double	aq_len = sqrt(len_sqr_v3(*ap) + lat->const_m);
	const t_vector3	aq = v3_mul(lat->opposite_orient, aq_len);

	h_rec->normal = v3_sub(*ap, aq);
	h_rec->normal = v3_normalize(h_rec->normal);
	set_face_normal(h_rec, ray, h_rec->normal);
}
