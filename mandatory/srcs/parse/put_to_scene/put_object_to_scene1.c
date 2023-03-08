/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_object_to_scene1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:46:12 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/09 03:39:10 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_internal.h"

int	put_point_light_to_scene(t_info *info, t_scene *scene)
{
	const t_info_object_point_light	*ptl_info = \
											(t_info_object_point_light *)info;
	const t_object_point_light		*ptl_obj;

	ptl_obj = (t_object_point_light *)new_point_light(ptl_info);
	if (ptl_obj == NULL)
		return (FAILURE);
	if (add_object(&scene->world.objects, (t_object *)ptl_obj) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	put_sphere_to_scene(t_info *info, t_scene *scene)
{
	const t_info_object_sphere	*sp_info = (t_info_object_sphere *)info;
	const t_object_sphere		*sp_obj;

	sp_obj = (t_object_sphere *)new_sphere(sp_info);
	if (sp_obj == NULL)
		return (FAILURE);
	if (add_object(&scene->world.objects, (t_object *)sp_obj) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	put_plane_to_scene(t_info *info, t_scene *scene)
{
	const t_info_object_plane	*pl_info = (t_info_object_plane *)info;
	const t_object_plane		*pl_obj;

	pl_obj = (t_object_plane *)new_plane(pl_info);
	if (pl_obj == NULL)
		return (FAILURE);
	if (add_object(&scene->world.objects, (t_object *)pl_obj) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	put_box_to_scene(t_info *info, t_scene *scene)
{
	const t_info_object_box	*bo_info = (t_info_object_box *)info;
	const t_object_box		*bo_obj;

	bo_obj = (t_object_box *)new_box(bo_info);
	if (bo_obj == NULL)
		return (FAILURE);
	if (add_object(&scene->world.objects, (t_object *)bo_obj) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
