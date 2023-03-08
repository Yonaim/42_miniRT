/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:19:21 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/09 07:30:19 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture_internal.h"
#include "s_info_element.h"

t_texture	*new_texture(t_info_texture *texture_info)
{
	if (texture_info->type == TEXTURE_SOLID)
		return (new_solid(texture_info->rgb1));
	else if (texture_info->type == TEXTURE_CHECKER)
		return (new_checker_single_solid(texture_info->rgb1));
	else if (texture_info->type == TEXTURE_IMAGE)
		return (NULL);
	return (NULL);
}
