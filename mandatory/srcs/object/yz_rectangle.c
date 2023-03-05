#include "object_internal.h"

static void	destroy_yz_rectangle(t_object *self);
static int	get_yz_rectangle_type(void);
static bool	hit_yz_rectangle(
				t_object *self,
				t_ray *ray, t_hit_record *h_rec, double t_max);

t_object	*new_yz_rectangle(t_info_object_yz_rectangle *yz_rec_info)
{
	t_object_yz_rectangle	*new;

	new = malloc(sizeof(t_object_yz_rectangle));
	if (new == NULL)
		return (NULL);
	new->destroy = destroy_yz_rectangle;
	new->get_type = get_yz_rectangle_type;
	new->hit = hit_yz_rectangle;
	new->material = new_material(&yz_rec_info->material, &yz_rec_info->texture);
	if (new->material == NULL)
		return (NULL);
	if (yz_rec_info->y1 > yz_rec_info->y2)
		swap_double_value(&yz_rec_info->y1, &yz_rec_info->y2);
	if (yz_rec_info->z1 > yz_rec_info->z2)
		swap_double_value(&yz_rec_info->z1, &yz_rec_info->z2);
	new->y1 = yz_rec_info->y1;
	new->y2 = yz_rec_info->y2;
	new->z1 = yz_rec_info->z1;
	new->z2 = yz_rec_info->z2;
	new->x = yz_rec_info->x;
	return ((t_object *)new);
}

static void	destroy_yz_rectangle(t_object *self)
{
	t_object_yz_rectangle	*rectangle;

	rectangle = (t_object_yz_rectangle *)self;
	rectangle->material->destroy(rectangle->material);
	free(rectangle);
}

static bool	hit_yz_rectangle(
			t_object *self, t_ray *in_ray, t_hit_record *h_rec, double t_maz)
{
	const t_object_yz_rectangle	*pl = (t_object_yz_rectangle *)self;
	const double				t = (pl->x - in_ray->origin.x) / in_ray->dir.x;
	double						y;
	double						z;

	if (t < T_MINIMUM || t > t_maz)
		return (false);
	y = in_ray->origin.y + t * in_ray->dir.y;
	z = in_ray->origin.z + t * in_ray->dir.z;
	if (y < pl->y1 || y > pl->y2 || z < pl->z1 || z > pl->z2)
		return (false);
	h_rec->u = (y - pl->y1) / (pl->y2 - pl->y1);
	h_rec->v = (z - pl->z1) / (pl->z2 - pl->z1);
	h_rec->t = t;
	h_rec->material = pl->material;
	h_rec->p = ray_at(in_ray, (double)t);
	set_face_normal(h_rec, in_ray, vector3(1, 0, 0));
	return (true);
}

static int	get_yz_rectangle_type(void)
{
	return (OBJECT_YZ_RECTANGLE);
}
