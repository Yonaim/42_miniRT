/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_material.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:46:12 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/07 18:46:12 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material_internal.h"
#include "s_info_element.h"

// texture type이 TEXTURE_NONE인 경우 texture 포인터에 널 포인터가 저장된다.
t_material	*new_material(const t_info_material *matl_info)
{
	const t_texture	*texture = new_texture(&matl_info->texture);

	if (matl_info->type == MATERIAL_LAMBERTIAN)
		return (new_lambertian(texture));
	else if (matl_info->type == MATERIAL_METAL)
		return (new_metal(texture, matl_info->fuzz));
	else if (matl_info->type == MATERIAL_DIELECTRIC)
		return (new_dielectric(matl_info->refractive_idx));
	else if (matl_info->type == MATERIAL_EMMISIVE)
		return (new_emmisive(matl_info->texture.rgb1));
	else if (matl_info->type == MATERIAL_RANDOM)
		return (new_random_material());
	return (NULL);
}
