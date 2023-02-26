#include "object_internal.h"

static bool	hit_xy_rectangle(\
						t_object *self, \
						t_ray *ray, t_hit_record *h_rec, double t_max);
static void	destroy_xy_rectangle(t_object *self);

t_object	*new_xy_rectangle(\
						const double x[2], const double y[2], const double k, \
						t_material *material)
{
	t_object_xy_rectangle	*new;

	new = malloc(sizeof(t_object_xy_rectangle));
	if (!new)
		return (NULL);
	new->x0 = x[0];
	new->x1 = x[1];
	new->y0 = y[0];
	new->y1 = y[1];
	new->k = k;
	new->material = material;
	new->hit = hit_xy_rectangle;
	new->destroy = destroy_xy_rectangle;
	return ((t_object *)new);
}

static bool	hit_xy_rectangle(\
						t_object *self, \
						t_ray *in_ray, t_hit_record *h_rec, double t_max)
{
	const t_object_xy_rectangle	*rc = (t_object_xy_rectangle *)self;
	const double				t = (rc->k - in_ray->origin.z) / in_ray->dir.z; 
	double						x;
	double						y;

	if (t < T_MINIMUM || t > t_max)
		return (false);
	x = in_ray->origin.x + t * in_ray->dir.x;
	y = in_ray->origin.y + t * in_ray->dir.y;
	if (x < rc->x0 || x > rc->x1 || y < rc->y0 || y > rc->y1)
		return (false);
	h_rec->u = (x - rc->x0) / (rc->x1 - rc->x0);
	h_rec->v = (y - rc->y0) / (rc->y1 - rc->y0);
	h_rec->t = t;
	set_face_normal(h_rec, in_ray, vector3(0, 0, 1));
	h_rec->material = rc->material;
	h_rec->p = ray_at(in_ray, (double)t);
	return (true);
}

static void	destroy_xy_rectangle(t_object *self)
{
	t_object_xy_rectangle	*rectangle;

	rectangle = (t_object_xy_rectangle *)self;
	rectangle->material->destroy(rectangle->material);
	free(rectangle);
}
