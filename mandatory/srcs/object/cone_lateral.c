# include "object_internal.h"

static void	destroy_cone_lateral(t_object *object);
static int	get_cone_lateral_type(void);
bool		hit_cone_lateral(
				t_object *self, t_ray *ray, t_hit_record *h_rec, double t_max);

t_object	*new_cone_lateral(const t_info_object_cone_lateral *lat_info)
{
	t_object_cone_lateral	*new;

	new = malloc(sizeof(t_object_cone_lateral));
	if (new == NULL)
		return (NULL);
	new->hit = hit_cone_lateral;
	new->destroy = destroy_cone_lateral;
	new->get_type = get_cone_lateral_type;
	new->material = new_material(&lat_info->material);
	if (new->material == NULL)
		return (NULL);
	new->center = lat_info->center;
	new->radius = lat_info->radius;
	new->height = lat_info->height;
	new->orient = lat_info->orient;
	new->opposite_orient = v3_mul(new->orient, -1);
	new->apex = v3_add(lat_info->center, \
					v3_mul(lat_info->orient, lat_info->height));
	new->const_m = pow(lat_info->radius, 2) / pow(lat_info->height, 2) + 1;
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
