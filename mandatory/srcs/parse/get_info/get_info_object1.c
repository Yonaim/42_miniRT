/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_object1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:46:12 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/13 14:07:00 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_internal.h"

/*
	(example)

	Solid element의 경우 '<elem_id> | <고유 정보> [material 및 texture]'와 같은 형식으로 들어온다.
		- material 및 texture가 없는 경우
			ex) sp | (0, 0, 20) 20 | (255, 0, 0)
		- material 및 texture가 있는 경우
			ex) sp | (0, 0, 20) 20 | lam sol (255, 0, 0)

	pl | (0,0,0) (0,1.0,0) | (255,0,225) 
	sp | (0,0,20) 20 | (255,0,0)
	cy | (50.0,0.0,20.6) (0.0,0.0,1.0) 14.2 21.42 | (10,0,255)
	co | (50.0,0.0,20.6) (0.0,0.0,1.0) 14.2 21.42 | (10,0,255)
	bo | (30,0,0) (0,20,10) | (255,255,255)
	(p_end1, p_end2, rgb)
*/

t_info	*get_info_point_light(const t_token_arr *tokens)
{
	t_info_object_point_light	*info;
	int							offset;

	info = malloc(sizeof(t_info_object_point_light));
	if (info == NULL)
		return (NULL);
	offset = 2;
	info->pos = parse_vector3(tokens, &offset);
	info->brightness = parse_number(tokens, &offset);
	offset++;
	info->rgb = parse_vector3(tokens, &offset);
	if (is_num_in_range(info->brightness, 0, 1) == false \
		|| is_color3_in_255(&info->rgb) == false)
	{
		free(info);
		return (NULL);
	}
	return ((t_info *)info);
}

t_info	*get_info_plane(const t_token_arr *tokens)
{
	t_info_object_plane	*info;
	int					offset;

	info = malloc(sizeof(t_info_object_plane));
	if (info == NULL)
		return (NULL);
	offset = 2;
	info->point = parse_vector3(tokens, &offset);
	info->normal = parse_vector3(tokens, &offset);
	info->material = get_info_material(tokens, offset);
	if (is_normalized_vec3(&info->normal) == false \
		|| is_color3_in_255(&info->material.texture.rgb1) == false)
	{
		free(info);
		return (NULL);
	}
	return ((t_info *)info);
}

t_info	*get_info_sphere(const t_token_arr *tokens)
{
	t_info_object_sphere	*info;
	int						offset;

	info = malloc(sizeof(t_info_object_sphere));
	if (info == NULL)
		return (NULL);
	offset = 2;
	info->center = parse_vector3(tokens, &offset);
	info->radius = parse_number(tokens, &offset) / 2;
	info->material = get_info_material(tokens, offset);
	if (info->radius > 0 \
		|| is_color3_in_255(&info->material.texture.rgb1) == false)
	{
		free(info);
		return (NULL);
	}
	return ((t_info *)info);
}

t_info	*get_info_box(const t_token_arr *tokens)
{
	t_info_object_box	*info;
	int					offset;

	info = malloc(sizeof(t_info_object_box));
	if (info == NULL)
		return (NULL);
	offset = 2;
	info->p_end1 = parse_vector3(tokens, &offset);
	info->p_end2 = parse_vector3(tokens, &offset);
	info->material = get_info_material(tokens, offset);
	if (is_color3_in_255(&info->material.texture.rgb1) == false)
	{
		free(info);
		return (NULL);
	}
	return ((t_info *)info);
}
