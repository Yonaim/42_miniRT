# include "object_internal.h"

static int	get_light_type(void);

t_object	*new_light(t_point3 pos, double ratio, t_color3 rgb)
{
	t_object_point_light	*new;

	new = malloc(sizeof(t_object_point_light));
	if (!new)
		return (NULL);
	ft_memset(new, 0, sizeof(t_object_point_light));
	new->pos = pos;
	new->material = new_emmisive(\
							v3_mul(\
								v3_div(rgb, 256), \
								ratio * MAX_BRIGHTNESS));
	new->get_type = get_light_type;
	if (new->material == NULL)
		return (NULL);
	return ((t_object *)new);
}

bool		hit_light(t_object *self, t_ray *ray, \
						t_hit_record *h_rec, double t_max)
{
	(void)self;
	(void)ray;
	(void)h_rec;
	(void)t_max;
	return (true);
}

static int	get_light_type(void)
{
return (OBJECT_POINT_LIGHT);
}