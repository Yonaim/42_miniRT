#include "object_internal.h"

static bool	hit_sphere(\
				t_object *self, t_ray *ray, \
				t_hit_record *h_rec, double t_max);
static void	get_sphere_uv(t_hit_record *record);
static void	destroy_sphere(t_object *object);


t_object	*new_sphere(t_point3 center, double radius, t_material *material)
{
	t_object_sphere	*new;

	new = malloc(sizeof(t_object_sphere));
	if (!new)
		return (NULL);
	new->center = center;
	new->radius = radius;
	new->hit = hit_sphere;
	new->destroy = destroy_sphere;
	new->material = material;
	return ((t_object *)new);
}

static bool	hit_sphere(\
				t_object *self, t_ray *in_ray, \
				t_hit_record *h_rec, double t_max)
{
	const t_object_sphere	*sp = (t_object_sphere *)self;
	const t_vector3			oc = v3_sub(in_ray->origin, sp->center);
	double					root[2];
	const bool				has_root = solve_quadratic(\
									len_sqr_v3(in_ray->dir), \
									v3_dot(oc, in_ray->dir), \
									len_sqr_v3(oc) - sp->radius * sp->radius, \
									root);
	t_vector3				outward_normal;

	if (has_root == false)
		return (false);
	h_rec->t = root[0];
	if (root[0] < T_MINIMUM || root[0] > t_max)
	{
		h_rec->t = root[1];
		if (root[1] < T_MINIMUM || root[1] > t_max)
			return (false);
	}
	h_rec->p = ray_at(in_ray, h_rec->t);
	h_rec->material = sp->material;
	outward_normal = v3_div(v3_sub(h_rec->p, sp->center), sp->radius);
	set_face_normal(h_rec, in_ray, outward_normal);
	get_sphere_uv(h_rec);
	return (true);
}

static void	get_sphere_uv(t_hit_record *record)
{
	const double	theta = acos(-record->p.y);
	const double	phi = atan2(-record->p.z, record->p.x) + M_PI;

	record->u = phi / (2 * M_PI);
	record->v = theta / M_PI;
}

static void	destroy_sphere(t_object *object)
{
	t_object_sphere	*sphere;

	sphere = (t_object_sphere *)object;
	free(sphere);
}
