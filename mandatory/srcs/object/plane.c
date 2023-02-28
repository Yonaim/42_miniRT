#include "object_internal.h"

t_object	*new_plane(t_point3 point, t_vector3 normal, t_material *material)
{
	t_object_plane	*new;

	new = malloc(sizeof(t_object_plane));
	if (!new)
		return (NULL);
	ft_memset(new, 0, sizeof(t_object_plane));
	new->point = point;
	new->normal = normal;
	new->material = material;
	return ((t_object *)new);
}

/*
	<Line-Plane intersection>

	Plane: (P - P0) * n = 0
		(P: point on the plane)
		(P0: known point that exist on a plane)
		(n: normal vector of a plane)

	Line: P(t) = o + t * dir
		(P(t): point this line points to)
		(O: origin of line)
		(dir: direction vector of line)
		(t: scalar value of the direction vector)

	Combining these two equations yields an equation for t.
	The solution of this equation is the case they intersect.

	-> t = (P0 - O) * n / (n * dir)
	(If there are countless solutions, 
	it means that a line is contained in the plane.)
	(If a given ray is contained in a plane, it is considered not hit)
*/
bool		hit_plane(t_object *self, t_ray *ray, \
						t_hit_record *h_rec, double t_max)
{
	const t_object_plane	*pl = (t_object_plane *)self;
	double					t;

	if (v3_dot(pl->normal, ray->dir) == 0)
		return (false);
	t = v3_div(\
			v3_dot(v3_sub(pl->point, ray->origin), pl->normal), \
			v3_dot(pl->normal, r->ray));
	h_rec->t = t;
	h_rec->p = ray_at(ray, t);
	h_rec->material = &pl->material;
	set_face_normal(h_rec, ray, pl->normal);
	return (true);	
}