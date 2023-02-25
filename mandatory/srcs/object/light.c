# include "object_internal.h"
static bool	hit_light(\
				t_object *self, t_ray *ray, t_hit_record *h_rec, double t_max);
static void	get_light_uv(t_hit_record *record);

t_object	*new_light(t_point3 pos, t_material *material)
{
	t_object_point_light	*new;

	new = malloc(sizeof(t_object_point_light));
	if (!new)
		return (NULL);
	ft_memset(new, 0, sizeof(t_object_point_light));
	new->pos = pos;
	new->material = material;
	new->hit = hit_light;
	return ((t_object *)new);
}

static bool	hit_light(\
			t_object *self, t_ray *ray, t_hit_record *h_rec, double t_max)
{
	const t_object_point_light	*li = (t_object_point_light *)self;

	(void)li;
	(void)ray;
	(void)h_rec;
	(void)t_max;
	get_light_uv(h_rec);
	return (true);
}

static void	get_light_uv(t_hit_record *record)
{
	(void)record;
}
