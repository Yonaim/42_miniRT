#include "object_internal.h"

static void	destroy_sphere(t_object *object);
static int	get_sphere_type(void);
static bool	hit_sphere(
				t_object *self, t_ray *ray, t_hit_record *h_rec, double t_max);
static bool	is_sphere_light(t_object *object);

t_object	*new_sphere(t_info_object_sphere *sp_info)
{
	t_object_sphere	*new;

	new = malloc(sizeof(t_object_sphere));
	if (new == NULL)
		return (NULL);
	new->hit = hit_sphere;
	new->destroy = destroy_sphere;
	new->get_type = get_sphere_type;
	new->is_light = is_sphere_light;
	new->material = new_material(&sp_info->material, &sp_info->texture);
	if (new->material == NULL)
		return (NULL);
	new->center = sp_info->center;
	new->radius = sp_info->radius;
	return ((t_object *)new);
}

static void	destroy_sphere(t_object *object)
{
	t_object_sphere	*sp;

	sp = (t_object_sphere *)object;
	sp->material->destroy(sp->material);
	free(sp);
}

static int	get_sphere_type(void)
{
	return (OBJECT_SPHERE);
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
static bool	hit_sphere(
			t_object *self, t_ray *ray, t_hit_record *h_rec, double t_max)
{
	const t_object_sphere	*sp = (t_object_sphere *)self;
	const t_vector3			co = v3_sub(ray->origin, sp->center);
	const double			coeff[3] = {
		len_sqr_v3(ray->dir),
		v3_dot(ray->dir, co),
		len_sqr_v3(co) - pow(sp->radius, 2)
	};
	double					root[2];
	double					t;

	if (solve_quadratic_half_b(coeff[A], coeff[B], coeff[C], root) == false)
		return (false);
	if (determine_t(&t, root, T_MINIMUM, t_max) == false)
		return (false);
	h_rec->t = t;
	h_rec->p = ray_at(ray, t);
	h_rec->material = sp->material;
	set_face_normal(h_rec, ray, v3_normalize(v3_sub(h_rec->p, sp->center)));
	return (true);
}
// dir * dir = len_sqr_v3(ray->dir)
// dir * (O - C) = v3_dot(ray->dir, oc)
// (O - C)^2 - r^2 = len_sqr_v3(oc) - pow(sp->radius, 2)
	// (O - C)^2 = len_sqr_v3(oc)
	// r^2 = pow(sp->radius, 2)

static bool	is_sphere_light(t_object *object)
{
	const t_object_sphere	*sp = (t_object_sphere *)object;

	if (sp->material->get_type() == MATERIAL_EMMISIVE)
		return (true);
	return (false);
}
