#include "material_internal.h"
#include "s_info_element.h"

// texture type이 TEXTURE_NONE인 경우 texture 포인터에 널 포인터가 저장된다.
t_material	*new_material(const t_info_material *material_info)
{
	const t_texture	*texture = new_texture(&material_info->texture);

	if (material_info->type == MATERIAL_LAMBERTIAN)
		return (new_lambertian(texture));
	else if (material_info->type == MATERIAL_METAL)
		return (new_metal(texture, material_info->fuzz));
	else if (material_info->type == MATERIAL_DIELECTRIC)
		return (new_dielectric(material_info->refractive_idx));
	else if (material_info->type == MATERIAL_EMMISIVE)
		return (new_emmisive(material_info->texture.rgb1));
	else if (material_info->type == MATERIAL_RANDOM)
		return (new_random_material());
	return (NULL);
}
