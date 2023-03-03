#include "object_internal.h"

/*
	<Line-Tube intersection>

	Tube: (P - C)^2 - ((P - C) * ^h)) - r^2 = 0
		(P: point on tube)
		(C: point at the center of the bottom disk)
		(^h: unit vector of the cylinder axis)
		(r: radius of the disk)

	Line: P(t) = o + t * dir
		(P(t): point this line points to)
		(O: origin of line)
		(dir: direction vector of line)
		(t: scalar value of the direction vector)

	Combining these two equations yields an equation for t.
	The solution of this equation is the case they intersect.

	-> at^2 + bt + c = 0
	value of each coefficient:
		a = (dir)^2 - (dir * ^h)^2
		b = 2 * (CO * dir - (CO * ^h)(dir * ^h))
		c = CO^2 - (CO * ^h)^2 - r^2
		(CO = O - C)
*/
static bool	solve_tube_intersection_equation(
				double root[2], const t_object_tube *tb, t_ray *ray);
static bool	is_tube_sol_in_range(t_vector3 *cp, const t_object_tube *tb);
static void	set_tube_face_normal(
				t_vector3 *cp,
				const t_object_tube *tb, t_ray *ray, t_hit_record *h_rec);

bool	hit_tube(
		t_object *self, t_ray *ray, t_hit_record *h_rec, double t_max)
{
	const t_object_tube	*tb = (t_object_tube *)self;
	double				root[2];
	double				t;
	t_vector3			cp;

	if (solve_tube_intersection_equation(root, tb, ray) == false)
		return (false);
	if (determine_t(&t, root, T_MINIMUM, t_max) == false)
		return (false);
	h_rec->t = t;
	h_rec->p = ray_at(ray, t);
	h_rec->material = tb->material;
	cp = v3_sub(h_rec->p, tb->center);
	if (is_tube_sol_in_range(&cp, tb) == false)
		return (false);
	set_tube_face_normal(&cp, tb, ray, h_rec);
	return (true);
}

static bool	solve_tube_intersection_equation(
			double root[2], const t_object_tube *tb, t_ray *ray)
{
	const t_vector3		co = v3_sub(ray->origin, tb->center);
	const double		dir_dot_ori = v3_dot(ray->dir, tb->orient);
	const double		co_dot_ori = v3_dot(co, tb->orient);
	const double		coeff[3] = {
		len_sqr_v3(ray->dir) - pow(dir_dot_ori, 2),
		v3_dot(co, ray->dir) - dir_dot_ori * co_dot_ori,
		len_sqr_v3(co) - pow(co_dot_ori, 2) - pow(tb->radius, 2)
	};

	if (fabs(coeff[A]) < EPSILON)
		return (false);
	if (solve_quadratic_half_b(coeff[A], coeff[B], coeff[C], root) == false)
		return (false);
	return (true);
}

static bool	is_tube_sol_in_range(t_vector3 *cp, const t_object_tube *tb)
{
	const double	height_from_center = v3_dot(tb->orient, *cp);

	if (height_from_center < 0 || height_from_center > tb->height)
		return (false);
	return (true);
}

static void	set_tube_face_normal(
			t_vector3 *cp,
			const t_object_tube *tb, t_ray *ray, t_hit_record *h_rec)
{
	h_rec->normal = v3_sub(*cp, v3_mul(tb->orient, v3_dot(tb->orient, *cp)));
	h_rec->normal = v3_normalize(h_rec->normal);
	set_face_normal(h_rec, ray, h_rec->normal);
}

// (dir)^2 = len_sqr_v3(ray->dir)	
// ^h = tb->orient
// (dir - ^h)^2 = len_sqr_v3(v3_sub(ray->dir, tb->orient))
// CO * dir = v3_dot(oc, ray->dir)
// CO * ^h = v3_dot(oc, tb->orient)
// (dir * ^h) = v3_dot(ray->dir, tb->orient)
// CO^2 = len_sqr_v3(oc)
// (CO - ^h)^2 = len_sqr_v3(v3_sub(oc, tb->orient))
// r^2 = pow(tb->radius, 2)

// hit point의 노멀 벡터
	// -> 이 노멀 벡터는 '원기둥 중심-P 벡터' 그리고 '원기둥 중심-P의 단면적 중심(oc)' 외적으로 구한다.
	// (두 벡터의 방향이 완전히 같거나 다른 경우, 외적 결과가 0이지만 유효한 원기둥이므로 그런 경우는 발생하지 않는다.)

// hit point의 노멀 벡터(수정)
	// 