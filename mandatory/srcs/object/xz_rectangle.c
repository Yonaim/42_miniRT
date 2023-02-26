#include "object_internal.h"

static bool	hit_xz_rectangle(\
						t_object *self, \
						t_ray *in_ray, t_hit_record *h_rec, double t_max);
static void	destroy_xz_rectangle(t_object *self);


t_object	*new_xz_rectangle(\
						const double x[2], const double z[2], const double k, \
						t_material *material)
{
	t_object_xz_rectangle	*new;

	new = malloc(sizeof(t_object_xz_rectangle));
	if (!new)
		return (NULL);
	new->x0 = x[0];
	new->x1 = x[1];
	new->z0 = z[0];
	new->z1 = z[1];
	new->k = k;
	new->material = material;
	new->hit = hit_xz_rectangle;
	new->destroy = destroy_xz_rectangle;
	return ((t_object *)new);
}

static bool	hit_xz_rectangle(\
						t_object *self, \
						t_ray *in_ray, t_hit_record *h_rec, double t_max)
{
	const t_object_xz_rectangle	*rc = (t_object_xz_rectangle *)self;
	const double				t = (rc->k - in_ray->origin.y) / in_ray->dir.y; 
	double						x; 
	double						z;

	if (t < T_MINIMUM || t > t_max)
		return (false);
	x = in_ray->origin.x + t * in_ray->dir.x;
	z = in_ray->origin.z + t * in_ray->dir.z;
	if (x < rc->x0 || x > rc->x1 || z < rc->z0 || z > rc->z1)
		return (false);
	h_rec->u = (x - rc->x0) / (rc->x1 - rc->x0);
	h_rec->v = (z - rc->z0) / (rc->z1 - rc->z0);
	h_rec->t = t;
	set_face_normal(h_rec, in_ray, vector3(0, 1, 0));
	h_rec->material = rc->material;
	h_rec->p = ray_at(in_ray, (double)t);
	return (true);
}

static void	destroy_xz_rectangle(t_object *self)
{
	t_object_xz_rectangle	*rectangle;

	rectangle = (t_object_xz_rectangle *)self;
	rectangle->material->destroy(rectangle->material);
	free(rectangle);
}
