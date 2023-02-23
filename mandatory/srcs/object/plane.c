#include "libft.h"
#include "s_object.h"

t_object	*create_plane(t_point3 pos, t_vector3 normal, t_color3 rgb)
{
	t_object_plane	*new;

	new = malloc(sizeof(t_object_plane));
	if (!new)
		return (NULL);
	ft_memset(new, 0, sizeof(t_object_plane));
	new->point = pos;
	new->normal = normal;
// 랜덤한 재질을 가지도록 수정
	new->material = malloc(sizeof(t_material_lambertian));
	new->material->albedo = v3_div(rgb, 255);
	return ((t_object *)new);
}
