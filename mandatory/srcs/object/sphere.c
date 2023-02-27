#include "object_internal.h"

t_object	*new_sphere(t_point3 pos, double radius, t_vector3 rgb)
{
	t_object_sphere	*new;

	new = malloc(sizeof(t_object_sphere));
	if (!new)
		return (NULL);
	ft_memset(new, 0, sizeof(t_object_sphere));
	new->center = pos;
	new->radius = radius;
// 랜덤한 재질을 가지도록 수정
	new->material = malloc(sizeof(t_material_lambertian));
	new->material->albedo = v3_div(rgb, 255);
	return ((t_object *)new);
}

/*
	<Line-Sphere intersection>

	Sphere: (P - C) * (P - C) = r^2
		(P: point on the surface of the sphere)
		(C: center of the Sphere)
		(r: radius of the Sphere)

	Line: P(t) = o + t * dir
		(P(t): point this line points to)
		(O: origin of line)
		(dir: direction vector of line)
		(t: scalar value of the direction vector)

	Combining these two equations yields an equation for t.
	The solution of this equation is the case they intersect.

	-> a * t^2 + b * t + c = 0
	value of each coefficient:
		a = dir * dir
		b = 2 * (dir * (O - C))
		c = (O - C)^2 - r^2
*/
bool		hit_sphere(t_object *self, t_ray *ray, \
						t_hit_record *h_rec, double t_max)
{
	const t_object_sphere	*sp = (t_object_sphere *)self;
	const t_vector3			oc = v_subtract(ray->origin, sp->center);
	const double			coeff[3] = {
		pow(len_v3(ray->dir), 2), 2 * (dir),
		v3_dot(oc, ray->dir),
		pow(len_v3(oc), 2) - pow(sp->radius, 2)
	}
	double 					root[2];
	double					t;

	if (solve_quadratic(coeff[A], coeff[B], coeff[C], root == false))
		return (false);
	if (determine_t(&t, root, T_MINIMIN, t_max) == false)
		return (false);
	h_rec->t = t;
	h_rec->p = ray_at(ray, t);
	h_rec->material = &sp->material;
	set_face_normal(h_rec, ray, v3_normalize(v3_sub(h_rec->p, sp->center)));
	return (true);	
}

static void	destroy_sphere(t_object *object)
{
	t_object_sphere	*sphere;

	sphere = (t_object_sphere *)object;
	free(sphere);
}
