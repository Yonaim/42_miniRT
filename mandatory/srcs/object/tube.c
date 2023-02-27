#include "object_internal.h"

static void	destroy_tube(t_object *object);
static int	get_tube_type(void);
static bool	hit_tube(t_object *self, t_ray *ray, \
						t_hit_record *h_rec, double t_max);

t_object	*new_tube(t_info_object_tube *info)
{
	t_object_tube	*new;

	new = malloc(sizeof(t_object_tube));
	if (!new)
		return (NULL);
	ft_memset(new, 0, sizeof(t_object_tube));
	new->center = v3_sub(info->center, v3_mul(info->orient, info->height / 2));
	new->radius = info->radius;
	new->height = info->height;
	new->orient = info->orient;
	new->material = new_material(&info->material, &info->texture);
	new->hit = hit_tube;
	new->destroy = destroy_tube;
	new->get_type = get_tube_type;
	return ((t_object *)new);
}

static void	destroy_tube(t_object *object)
{
	t_object_tube	*tube;

	tube = (t_object_tube *)object;
	tube->material->destroy(tube->material);
	free(tube);
}

static int	get_tube_type(void)
{
	return (OBJECT_TUBE);
}

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
		a = (dir)^2 - (dir - ^h)^2
		b = 2 * (CO * dir - (CO * ^h)(dir * ^h))
		c = CO^2 - (CO - ^h)^2 - r^2
		(CO = O - C)
*/

static void	set_tube_normal_vector(t_object_tube *tb, t_hit_record *h_rec)
{
	const t_vector3	cp = v3_sub(h_rec->p, v3_sub(tb->center, \
									v3_mul((tb->orient), tb->height / 2)));
	
	h_rec->normal = v3_sub(cp, v3_mul(tb->orient, v3_dot(tb->orient, cp)));
}

static bool	hit_tube(t_object *self, t_ray *ray, \
						t_hit_record *h_rec, double t_max)
{
	const t_object_tube		*tb = (t_object_tube *)self;
	const t_vector3			co = v3_sub(ray->origin, \
									v3_sub(tb->center, \
									v3_mul((tb->orient), tb->height / 2)));
	const double			coeff[3] = {
		len_sqr_v3(ray->dir) - len_sqr_v3(v3_sub(ray->dir, tb->orient)),
		2 * (v3_dot(co, ray->dir) \
				- v3_dot(co, tb->orient) * v3_dot(ray->dir, tb->orient)),
		len_sqr_v3(co) - len_sqr_v3(v3_sub(co, tb->orient)) - pow(tb->radius, 2)
	};
	double					root[2];
	double					t;

	if (solve_quadratic(coeff[A], coeff[B], coeff[C], root) == false)
		return (false);
	if (determine_t(&t, root, T_MINIMUM, t_max) == false)
		return (false);
	h_rec->t = t;
	h_rec->p = ray_at(ray, t);
	h_rec->material = tb->material;
	set_tube_normal_vector(tb, h_rec);
	set_face_normal(h_rec, ray, v3_cross(v3_sub(tb->center, h_rec->p), co));
	return (true);
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