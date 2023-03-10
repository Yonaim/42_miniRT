/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_identifier_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:18:52 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/09 03:58:22 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_internal_bonus.h"

static int	get_idx_matching_string(const char **strs, const char *seek)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		if (ft_strcmp(seek, strs[i]) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int	get_element_type(const char *str)
{
	const char	*identifier[] = {
	[ELEMENT_AMBIENT] = IDENTIFIER_ELEMENT_AMBIENT,
	[ELEMENT_CAMERA] = IDENTIFIER_ELEMENT_CAMERA,
	[ELEMENT_LIGHT] = IDENTIFIER_ELEMENT_LIGHT,
	[ELEMENT_PLANE] = IDENTIFIER_ELEMENT_PLANE,
	[ELEMENT_SPHERE] = IDENTIFIER_ELEMENT_SPHERE,
	[ELEMENT_DISK] = IDENTIFIER_ELEMENT_DISK,
	[ELEMENT_TUBE] = IDENTIFIER_ELEMENT_TUBE,
	[ELEMENT_CYLINDER] = IDENTIFIER_ELEMENT_CYLINDER,
	[ELEMENT_CONE_LATERAL] = IDENTIFIER_ELEMENT_CONE_LATERAL,
	[ELEMENT_CONE] = IDENTIFIER_ELEMENT_CONE,
	[ELEMENT_BOX] = IDENTIFIER_ELEMENT_BOX,
	[ELEMENT_NONE] = NULL
	};

	return (get_idx_matching_string(identifier, str));
}

int	get_material_type(const char *str)
{
	const char	*identifier[] = {
	[MATERIAL_LAMBERTIAN] = IDENTIFIER_MATERIAL_LAMBERTIAL,
	[MATERIAL_METAL] = IDENTIFIER_MATERIAL_METAL,
	[MATERIAL_DIELECTRIC] = IDENTIFIER_MATERIAL_DIELECTRIC,
	[MATERIAL_EMMISIVE] = IDENTIFIER_MATERIAL_EMMISIVE,
	[MATERIAL_RANDOM] = IDENTIFIER_MATERIAL_RANDOM,
	[MATERIAL_NONE] = NULL
	};

	return (get_idx_matching_string(identifier, str));
}

int	get_texture_type(const char *str)
{
	const char	*identifier[] = {
	[TEXTURE_SOLID] = IDENTIFIER_TEXTURE_SOLID,
	[TEXTURE_CHECKER] = IDENTIFIER_TEXTURE_CHECKER,
	[TEXTURE_IMAGE] = IDENTIFIER_TEXTURE_IMAGE,
	[TEXTURE_NONE] = NULL
	};

	return (get_idx_matching_string(identifier, str));
}
