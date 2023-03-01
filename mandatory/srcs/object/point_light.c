#include "object_internal.h"

static void	destroy_point_light(t_object *self);
static bool	hit_point_light(t_object *self, t_ray *ray, \
						t_hit_record *h_rec, double t_max);
static int	get_point_light_type(void);

t_object	*new_point_light(t_point3 pos, double ratio, t_color3 rgb)
{
	t_object_point_light	*new;

	new = malloc(sizeof(t_object_point_light));
	if (!new)
		return (NULL);
	new->hit = hit_point_light;
	new->destroy = destroy_point_light;
	new->get_type = get_point_light_type;
	new->material = new_emmisive(v3_mul(v3_div(rgb, 256), \
										ratio * MAX_BRIGHTNESS));
	new->sphere = new_sphere(pos, POINT_LIGHT_RADIUS, new->material);
	if (new->material == NULL || new->sphere == NULL)
		return (NULL);
	return ((t_object *)new);
}

static void	destroy_point_light(t_object *self)
{
	t_object_point_light	*point_light;

	point_light = (t_object_point_light *)self;
	point_light->material->destroy(point_light->material);
	free(point_light);
}

static int	get_point_light_type(void)
{
	return (OBJECT_POINT_LIGHT);
}

static bool	hit_point_light(t_object *self, t_ray *ray, \
						t_hit_record *h_rec, double t_max)
{
	t_object	*spherical_point_light;

	spherical_point_light = ((t_object_point_light *)self)->sphere;
	return (spherical_point_light->hit(\
									spherical_point_light, ray, h_rec, t_max));
}
