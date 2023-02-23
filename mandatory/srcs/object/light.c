# include "object_internal.h"

t_object	*create_light(t_point3 pos, double ratio, t_color3 rgb)
{
	t_object_point_light	*new;

	new = malloc(sizeof(t_object_point_light));
	if (!new)
		return (NULL);
	ft_memset(new, 0, sizeof(t_object_point_light));
	new->pos = pos;
	new->material = malloc(sizeof(t_material_emmisive));
	new->material->albedo = v3_mul(rgb, ratio / 255);
	return ((t_object *)new);
}