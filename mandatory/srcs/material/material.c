#include "material_internal.h"
#include "s_info_element.h"

t_material	*new_material(\
				t_info_material *material_info, t_info_texture *texture_info)
{
	t_texture	*texture;

	texture = new_texture(texture_info);
	if (material_info->type == MATERIAL_LAMBERTIAN)
		return (new_lambertian(texture));
	else if (material_info->type == MATERIAL_METAL)
		return (new_metal(material_info->rgb, material_info->fuzz));
	else if (material_info->type == MATERIAL_DIELECTRIC)
		return (new_dielectric(material_info->refractive_idx));
	else if (material_info->type == MATERIAL_EMMISIVE)
		return (new_emmisive(material_info->rgb));
	else if (material_info->type == MATERIAL_RANDOM)
		return (new_random_material());
	return (NULL);
}
