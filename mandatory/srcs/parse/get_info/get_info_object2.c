/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_object2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 03:36:14 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/14 10:12:15 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_internal.h"

t_info	*get_info_disk(const t_token_arr *tokens)
{
	t_info_object_disk	*info;
	int					offset;

	info = malloc(sizeof(t_info_object_disk));
	if (info == NULL)
		return (NULL);
	offset = 2;
	info->center = parse_vector3(tokens, &offset);
	info->normal = parse_vector3(tokens, &offset);
	info->radius = parse_number(tokens, &offset) / 2;
	while (nth_token(tokens, offset)->type == TOKEN_NUMBER)
		offset++;
	info->material = get_info_material(tokens, offset);
	if (info->radius <= 0 \
		|| is_normalized_vec3(&info->normal) == false \
		|| is_color3_in_255(&info->material.texture.rgb1) == false)
	{
		free(info);
		return (NULL);
	}
	return ((t_info *)info);
}

t_info	*get_info_tube(const t_token_arr *tokens)
{
	t_info_object_tube	*info;
	int					offset;

	info = malloc(sizeof(t_info_object_tube));
	if (info == NULL)
		return (NULL);
	offset = 2;
	info->center = parse_vector3(tokens, &offset);
	info->orient = parse_vector3(tokens, &offset);
	info->radius = parse_number(tokens, &offset) / 2;
	info->height = parse_number(tokens, &offset);
	info->material = get_info_material(tokens, offset);
	if (info->radius <= 0
		|| info->height <= 0 \
		|| is_normalized_vec3(&info->orient) == false \
		|| is_color3_in_255(&info->material.texture.rgb1) == false)
	{
		free(info);
		return (NULL);
	}
	return ((t_info *)info);
}

t_info	*get_info_cylinder(const t_token_arr *tokens)
{
	t_info_object_cylinder	*cy_info;
	t_info_object_disk		*di_info;
	t_info_object_tube		*tu_info;

	cy_info = malloc(sizeof(t_info_object_cylinder));
	di_info = (t_info_object_disk *)get_info_disk(tokens);
	tu_info = (t_info_object_tube *)get_info_tube(tokens);
	if (cy_info == NULL || di_info == NULL || tu_info == NULL)
		return (NULL);
	ft_memcpy(&cy_info->disk[0], di_info, sizeof(t_info_object_disk));
	ft_memcpy(&cy_info->disk[1], di_info, sizeof(t_info_object_disk));
	ft_memcpy(&cy_info->tube, tu_info, sizeof(t_info_object_tube));
	cy_info->disk[0].center = v3_sub(tu_info->center, \
								v3_mul(tu_info->orient, tu_info->height / 2));
	cy_info->disk[1].center = v3_add(tu_info->center, \
								v3_mul(tu_info->orient, tu_info->height / 2));
	free(di_info);
	free(tu_info);
	return ((t_info *)cy_info);
}

t_info	*get_info_cone_lateral(const t_token_arr *tokens)
{
	t_info_object_cone_lateral	*info;
	int							offset;

	info = malloc(sizeof(t_info_object_cone_lateral));
	if (info == NULL)
		return (NULL);
	offset = 2;
	info->center = parse_vector3(tokens, &offset);
	info->orient = parse_vector3(tokens, &offset);
	info->radius = parse_number(tokens, &offset) / 2;
	info->height = parse_number(tokens, &offset);
	info->material = get_info_material(tokens, offset);
	if (info->radius <= 0 \
		|| info->height <= 0 \
		|| is_normalized_vec3(&info->orient) == false \
		|| is_color3_in_255(&info->material.texture.rgb1) == false)
	{
		free(info);
		return (NULL);
	}
	return ((t_info *)info);
}

t_info	*get_info_cone(const t_token_arr *tokens)
{
	t_info_object_cone			*co_info;
	t_info_object_disk			*di_info;
	t_info_object_cone_lateral	*cl_info;

	co_info = malloc(sizeof(t_info_object_cone));
	di_info = (t_info_object_disk *)get_info_disk(tokens);
	cl_info = (t_info_object_cone_lateral *)get_info_cone_lateral(tokens);
	if (co_info == NULL || di_info == NULL || cl_info == NULL)
		return (NULL);
	ft_memcpy(&co_info->disk, di_info, sizeof(t_info_object_disk));
	ft_memcpy(&co_info->lateral, cl_info, sizeof(t_info_object_cone_lateral));
	free(di_info);
	free(cl_info);
	return ((t_info *)co_info);
}
