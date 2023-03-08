/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_material.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 03:35:28 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/09 03:35:47 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_internal.h"

t_info_material	get_info_material(const t_token_arr *tokens, int offset)
{
	t_info_material	matl_info;

	offset++;
	if (nth_token(tokens, offset)->type == TOKEN_IDENTIFIER_MATERIAL)
	{
		matl_info.type = get_material_type(nth_token(tokens, offset++)->str);
		if (matl_info.type == MATERIAL_METAL)
			matl_info.fuzz = parse_number(tokens, &offset);
		else if (matl_info.type == MATERIAL_DIELECTRIC)
			matl_info.refractive_idx = parse_number(tokens, &offset);
		if (matl_info.type != MATERIAL_DIELECTRIC)
			matl_info.texture = get_info_texture(tokens, offset);
	}
	else
	{
		matl_info.type = DEFAULT_MATERIAL;
		matl_info.texture.type = DEFAULT_TEXTURE;
		matl_info.texture.rgb1 = parse_vector3(tokens, &offset);
	}	
	return (matl_info);
}
