# include "object_internal.h"

static void	destroy_cone_lateral(t_object *object);
static int	get_cone_lateral_type(void);
static bool	hit_cone_lateral(t_object *self, t_ray *ray, \
						t_hit_record *h_rec, double t_max);

t_object	*new_cone_lateral(t_point3 center, double radius, double height, \
						t_material *material)
{
	t_object_cone_lateral	*new;

	new = malloc(sizeof(t_object_cone_lateral));
	if (new == NULL)
		return (NULL);
	new->hit = hit_cone_lateral;
	new->destroy = destroy_cone_lateral;
	new->get_type = get_cone_lateral_type;
	(void)center;
	(void)radius;
	(void)height;
	(void)material;
	return ((t_object *)new);
}

static void	destroy_cone_lateral(t_object *object)
{
	t_object_cone_lateral	*lat;

	lat = (t_object_cone_lateral *)object;
	lat->material->destroy(lat->material);
	free(lat);
}

static int	get_cone_lateral_type(void)
{
	return (OBJECT_CONE_LATERAL);
}

static bool	hit_cone_lateral(t_object *self, t_ray *ray, \
						t_hit_record *h_rec, double t_max)
{
	(void)self;
	(void)ray;
	(void)h_rec;
	(void)t_max;
	return (true);
}