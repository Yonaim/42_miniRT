#include "object_internal.h"

t_object	*new_sphere(t_point3 pos, double radius, t_vector3 rgb)
{
	t_object_sphere	*new;

	new = malloc(sizeof(t_object_sphere));
	if (!new)
		return (NULL);
	ft_memset(new, 0, sizeof(t_object_sphere));
	new->center = pos;
	new->radius = radius;
// 랜덤한 재질을 가지도록 수정
	new->material = malloc(sizeof(t_material_lambertian));
	new->material->albedo = v3_div(rgb, 255);
	return ((t_object *)new);
}
