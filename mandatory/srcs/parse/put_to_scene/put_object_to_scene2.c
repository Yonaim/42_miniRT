/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_object_to_scene2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 03:27:44 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/09 03:39:13 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_internal.h"

int	put_disk_to_scene(t_info *info, t_scene *scene)
{
	const t_info_object_disk	*di_info = (t_info_object_disk *)info;
	const t_object_disk			*di_obj;

	di_obj = (t_object_disk *)new_disk(di_info);
	if (di_obj == NULL)
		return (FAILURE);
	if (add_object(&scene->world.objects, (t_object *)di_obj) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	put_tube_to_scene(t_info *info, t_scene *scene)
{
	const t_info_object_tube	*tu_info = (t_info_object_tube *)info;
	const t_object_tube			*tu_obj;

	tu_obj = (t_object_tube *)new_tube(tu_info);
	if (tu_obj == NULL)
		return (FAILURE);
	if (add_object(&scene->world.objects, (t_object *)tu_obj) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	put_cylinder_to_scene(t_info *info, t_scene *scene)
{
	const t_info_object_cylinder	*cy_info = (t_info_object_cylinder *)info;
	const t_object_cylinder			*cy_obj;

	cy_obj = (t_object_cylinder *)new_cylinder(cy_info);
	if (cy_obj == NULL)
		return (FAILURE);
	if (add_object(&scene->world.objects, (t_object *)cy_obj) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	put_cone_lateral_to_scene(t_info *info, t_scene *scene)
{
	const t_info_object_cone_lateral	*cl_info = \
											(t_info_object_cone_lateral *)info;
	const t_object_cone_lateral			*cl_obj;

	cl_obj = (t_object_cone_lateral *)new_cone_lateral(cl_info);
	if (cl_obj == NULL)
		return (FAILURE);
	if (add_object(&scene->world.objects, (t_object *)cl_obj) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	put_cone_to_scene(t_info *info, t_scene *scene)
{
	const t_info_object_cone	*co_info = (t_info_object_cone *)info;
	const t_object_cone			*co_obj;

	co_obj = (t_object_cone *)new_cone(co_info);
	if (co_obj == NULL)
		return (FAILURE);
	if (add_object(&scene->world.objects, (t_object *)co_obj) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
