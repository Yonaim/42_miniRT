#include "object_internal.h"

static bool	hit_yz_rectangle(\
						t_object *self, \
						t_ray *in_ray, t_hit_record *h_rec, double t_maz);

static void	destroy_yz_rectangle(t_object *self);

t_object	*new_yz_rectangle(\
						 const double y[2], const double z[2], const double k, \
						t_material *material)
{
	t_object_yz_rectangle	*new;

	new = malloc(sizeof(t_object_yz_rectangle));
	if (!new)
		return (NULL);
	new->y0 = y[0];
	new->y1 = y[1];
	new->z0 = z[0];
	new->z1 = z[1];
	new->k = k;
	new->material = material;
	new->hit = hit_yz_rectangle;
	new->destroy = destroy_yz_rectangle;
	return ((t_object *)new);
}

static bool	hit_yz_rectangle(\
						t_object *self, \
						t_ray *in_ray, t_hit_record *h_rec, double t_maz)
{
	const t_object_yz_rectangle	*pl = (t_object_yz_rectangle *)self;
	const double				t = (pl->k - in_ray->origin.x) / in_ray->dir.x; 
	double						y;
	double						z;

	if (t < T_MINIMUM || t > t_maz)
		return (false);
	y = in_ray->origin.y + t * in_ray->dir.y;
	z = in_ray->origin.z + t * in_ray->dir.z;
	if (y < pl->y0 || y > pl->y1 || z < pl->z0 || z > pl->z1)
		return (false);
	h_rec->u = (y - pl->y0) / (pl->y1 - pl->y0);
	h_rec->v = (z - pl->z0) / (pl->z1 - pl->z0);
	h_rec->t = t;
	set_face_normal(h_rec, in_ray, vector3(1, 0, 0));
	h_rec->material = pl->material;
	h_rec->p = ray_at(in_ray, (double)t);
	return (true);
}

static void	destroy_yz_rectangle(t_object *self)
{
	t_object_yz_rectangle	*rectangle;

	rectangle = (t_object_yz_rectangle *)self;
	rectangle->material->destroy(rectangle->material);
	free(rectangle);
}
