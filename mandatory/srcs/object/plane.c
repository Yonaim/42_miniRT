#include "object_internal.h"

static bool	hit_plane(\
			t_object *self, t_ray *ray, t_hit_record *h_rec, double t_max);
static void	get_plane_uv(t_hit_record *record);

t_object	*new_plane(t_point3 pos, t_vector3 normal, t_material *material)
{
	t_object_plane	*new;

	new = malloc(sizeof(t_object_plane));
	if (!new)
		return (NULL);
	ft_memset(new, 0, sizeof(t_object_plane));
	new->point = pos;
	new->normal = normal;
	new->material = material;
	new->hit = hit_plane;
	return ((t_object *)new);
}

static bool	hit_plane(\
			t_object *self, t_ray *ray, t_hit_record *h_rec, double t_max)
{
	const t_object_plane	*pl = (t_object_plane *)self;

	(void)pl;
	(void)ray;
	(void)h_rec;
	(void)t_max;
	get_plane_uv(h_rec);
	return (true);
}

static void	get_plane_uv(t_hit_record *record)
{
	(void)record;
}