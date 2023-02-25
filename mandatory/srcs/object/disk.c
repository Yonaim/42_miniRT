#include "object_internal.h"

static bool	hit_disk(\
				t_object *self, t_ray *ray, t_hit_record *h_rec, double t_max);
static void	get_disk_uv(t_hit_record *record);

t_object	*new_disk(t_point3 pos, double radius, t_material *material)
{
	t_object_disk	*new;

	new = malloc(sizeof(t_object_disk));
	if (!new)
		return (NULL);
	ft_memset(new, 0, sizeof(t_object_disk));
	new->center = pos;
	new->radius = radius;
	new->hit = hit_disk;
	new->material = material;
	return ((t_object *)new);
}

static bool	hit_disk(\
			t_object *self, t_ray *ray, t_hit_record *h_rec, double t_max)
{
	const t_object_disk	*dk = (t_object_disk *)self;

	(void)dk;
	(void)ray;
	(void)h_rec;
	(void)t_max;
	get_disk_uv(h_rec);
	return (true);
}

static void	get_disk_uv(t_hit_record *record)
{
	(void)record;
}
