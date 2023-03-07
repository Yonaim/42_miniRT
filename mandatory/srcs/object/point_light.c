#include "object_internal.h"

static void	destroy_point_light(t_object *self);
static int	get_point_light_type(void);
static bool	hit_point_light(
				t_object *self, t_ray *ray, t_hit_record *h_rec, double t_max);
static bool	is_point_light(t_object *object);
double		calculate_point_light_sampling_pdf(
				t_object *self, const t_vector3 *origin, const t_vector3 *dir);
t_vector3	get_random_vector_to_point_light(
				const t_object *self, const t_point3 *origin);

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
	new->is_light = is_point_light;
	new->pdf_value = calculate_point_light_sampling_pdf;
	new->random = get_random_vector_to_point_light;
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
	// ptl->material->destroy(ptl->material);
	ptl->sphere->destroy(ptl->sphere);
	free(ptl);
}

static int	get_point_light_type(void)
{
	return (OBJECT_POINT_LIGHT);
}

//https://mathworld.wolfram.com/Point-LineDistance3-Dimensional.html
static bool	hit_point_light(
			t_object *self, t_ray *ray, t_hit_record *h_rec, double t_max)
{
	t_object	*spherical_ptl;

	spherical_ptl = ((t_object_point_light *)self)->sphere;
	return (spherical_ptl->hit(spherical_ptl, ray, h_rec, t_max));
// 	const t_object_point_light	*ptl = (t_object_point_light *)self;
// 	const t_vector3				origin_to_pt = v3_sub(ptl->center, ray->origin);

// 	if (is_near_zero(v3_cross(ray->dir, origin_to_pt)) == false)
// 		return (false);
// // error_log("hit light point");
// 	if (ray->dir.x > 0.01)
// 		h_rec->t = (ptl->center.x - ray->origin.x) / ray->dir.x;
// 	else if (ray->dir.y > 0.01)
// 		h_rec->t = (ptl->center.y - ray->origin.y) / ray->dir.y;
// 	else
// 		h_rec->t = (ptl->center.z - ray->origin.z) / ray->dir.z;
// 	if (h_rec->t < T_MINIMUM || h_rec->t > t_max)
// 		return (false);
// 	h_rec->p = ptl->center;
// 	h_rec->material = ptl->material;
// 	h_rec->opposed = true;
// 	h_rec->normal = v3_mul(origin_to_pt, -1);
// 	return (true);
}

static bool	is_point_light(t_object *object)
{
	(void)object;
	return (true);
}
