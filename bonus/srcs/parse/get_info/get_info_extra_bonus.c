/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:46:12 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/09 03:42:02 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_internal_bonus.h"

/*
	(example)
	A | 0.2 (255, 255, 255)
	C | (-50, 0, 20) (0, 0, 0) 70
	L | (-40, 0, 30) 0.7 (255, 255, 255)
*/

t_info	*get_info_ambient(const t_token_arr *tokens)
{
	t_info_ambient_light	*info;
	int						offset;

	info = malloc(sizeof(t_info_ambient_light));
	if (info == NULL)
		return (NULL);
	offset = 2;
	info->brightness = parse_number(tokens, &offset);
	info->rgb = parse_vector3(tokens, &offset);
	if (is_num_in_range(info->brightness, 0, 1) == false \
		|| is_color3_in_255(&info->rgb) == false)
	{
		free(info);
		return (NULL);
	}
	return ((t_info *)info);
}

t_info	*get_info_camera(const t_token_arr *tokens)
{
	t_info_camera	*info;
	int				offset;

	info = malloc(sizeof(t_info_camera));
	if (info == NULL)
		return (NULL);
	offset = 2;
	info->origin = parse_vector3(tokens, &offset);
	info->orient = parse_vector3(tokens, &offset);
	info->fov = parse_number(tokens, &offset);
	if (is_normalized_vec3(&info->orient) == false \
		|| is_num_in_range(info->fov, 0, 180) == false)
	{
		free(info);
		return (NULL);
	}
	return ((t_info *)info);
}
