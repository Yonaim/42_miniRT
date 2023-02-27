#include "object_internal.h"

static void	destroy_point_light(t_object *self);
static int	get_point_light_type(void);
static bool	hit_point_light(
				t_object *self, t_ray *ray, t_hit_record *h_rec, double t_max);

t_object	*new_point_light(t_info_object_point_light *ptl_info)
{
	t_object_point_light	*new;
	t_info_object_sphere	sp_info;

	new = malloc(sizeof(t_object_point_light));
	if (new == NULL)
		return (NULL);
	new->hit = hit_point_light;
	new->destroy = destroy_point_light;
	new->get_type = get_point_light_type;
	sp_info.center = ptl_info->pos;
	sp_info.radius = POINT_LIGHT_RADIUS;
	sp_info.material.type = MATERIAL_EMMISIVE;
	sp_info.material.rgb = v3_mul(ptl_info->rgb, ptl_info->brightness);
	new->sphere = new_sphere(&sp_info);
	if (new->sphere == NULL)
		return (NULL);
	return ((t_object *)new);
}

static void	destroy_point_light(t_object *self)
{
	t_object_point_light	*ptl;

	ptl = (t_object_point_light *)self;
	ptl->sphere->destroy(ptl->sphere);
	free(ptl);
}

static int	get_point_light_type(void)
{
	return (OBJECT_POINT_LIGHT);
}

static bool	hit_point_light(
			t_object *self, t_ray *ray, t_hit_record *h_rec, double t_max)
{
	t_object	*spherical_ptl;

	spherical_ptl = ((t_object_point_light *)self)->sphere;
	return (spherical_ptl->hit(spherical_ptl, ray, h_rec, t_max));
}
