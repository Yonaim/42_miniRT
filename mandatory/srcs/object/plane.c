 #include "object_internal.h"

static void	destroy_plane(t_object *object);
static int	get_plane_type(void);
static bool	hit_plane(
				t_object *self, t_ray *ray, t_hit_record *h_rec, double t_max);

t_object	*new_plane(const t_info_object_plane *pl_info)
{
	t_object_plane	*new;

	new = malloc(sizeof(t_object_plane));
	if (new == NULL)
		return (NULL);
	new->hit = hit_plane;
	new->destroy = destroy_plane;
	new->get_type = get_plane_type;
	new->material = new_material(&pl_info->material);
	if (new->material == NULL)
		return (NULL);
	new->point = pl_info->point;
	new->normal = pl_info->normal;
	return ((t_object *)new);
}

static void	destroy_plane(t_object *object)
{
	t_object_plane	*pl;

	pl = (t_object_plane *)object;
	pl->material->destroy(pl->material);
	free(pl);
}

static int	get_plane_type(void)
{
	return (OBJECT_PLANE);
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
static bool	hit_plane(
			t_object *self, t_ray *ray, t_hit_record *h_rec, double t_max)
{
	const t_object_plane	*pl = (t_object_plane *)self;
	double					t;

	if (fabs(v3_dot(pl->normal, ray->dir)) < EPSILON)
		return (false);
	t = v3_dot(v3_sub(pl->point, ray->origin), pl->normal) \
		/ v3_dot(pl->normal, ray->dir);
	if (t < T_MINIMUM || t > t_max)
		return (false);
	h_rec->t = t;
	h_rec->p = ray_at(ray, t);
	h_rec->material = pl->material;
	set_face_normal(h_rec, ray, pl->normal);
	return (true);
}
