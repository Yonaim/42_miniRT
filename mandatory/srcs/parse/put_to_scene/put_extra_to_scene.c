/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_extra_to_scene.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:46:12 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/09 03:39:24 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_internal.h"

int	put_ambient_to_scene(t_info *info, t_scene *scene)
{
	const t_info_ambient_light	*amb_info = (t_info_ambient_light *)info;

	scene->world.background_color = v3_mul(amb_info->rgb, \
										amb_info->brightness / 255);
	return (1);
}

int	put_camera_to_scene(t_info *info, t_scene *scene)
{
	const t_info_camera	*cam_info = (t_info_camera *)info;

	scene->cam.basis.dir = v3_mul(cam_info->orient, -1);
	scene->cam.viewport.fov = cam_info->fov;
	scene->cam.origin = cam_info->origin;
	return (1);
}
