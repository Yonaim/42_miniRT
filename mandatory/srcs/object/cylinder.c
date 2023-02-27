# include "object_internal.h"

t_object	*new_cylinder(\
					t_point3 pos, t_vector3 orient, \
					double radius, double height, t_color3 rgb)
{
	t_object_cylinder	*new;

	new = malloc(sizeof(t_object_cylinder));
	if (!new)
		return (NULL);
	ft_memset(new, 0, sizeof(t_object_cylinder));
	new->center = pos;
	new->orient = orient;
	new->radius = radius;
	new->height = height;
	new->material = malloc(sizeof(t_material_lambertian));
// 랜덤한 재질을 가지도록 수정
	new->material->albedo = v3_div(rgb, 255);
	return ((t_object *)new);
}

bool	hit_cylinder(t_object *self, t_ray *ray, \
						t_hit_record *h_rec, double t_max)
{
	(void)self;
	(void)ray;
	(void)t_max;
	(void)
}
