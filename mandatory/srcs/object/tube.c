#include "object_internal.h"

static void	destroy_tube(t_object *object);
static int	get_tube_type(void);
bool		hit_tube(
				t_object *self, t_ray *ray, t_hit_record *h_rec, double t_max);

t_object	*new_tube(t_info_object_tube *info)
{
	t_object_tube	*new;

	new = malloc(sizeof(t_object_tube));
	if (new == NULL)
		return (NULL);
	ft_memset(new, 0, sizeof(t_object_tube));
	new->hit = hit_tube;
	new->destroy = destroy_tube;
	new->get_type = get_tube_type;
	new->material = new_material(&info->material);
	if (new->material == NULL)
		return (NULL);
	new->center = v3_sub(info->center, v3_mul(info->orient, info->height / 2));
	new->radius = info->radius;
	new->height = info->height;
	new->orient = info->orient;
	return ((t_object *)new);
}

static void	destroy_tube(t_object *object)
{
	t_object_tube	*tube;

	tube = (t_object_tube *)object;
	tube->material->destroy(tube->material);
	free(tube);
}

static int	get_tube_type(void)
{
	return (OBJECT_TUBE);
}
