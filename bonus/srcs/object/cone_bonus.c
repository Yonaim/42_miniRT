/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:46:12 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/09 03:58:28 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object_internal_bonus.h"

static void	destroy_cone(t_object *object);
static int	get_cone_type(void);
static bool	hit_cone(
				t_object *self, t_ray *ray, t_hit_record *h_rec, double t_max);

t_object	*new_cone(const t_info_object_cone *co_info)
{
	t_object_cone	*new;

	new = malloc(sizeof(t_object_cone));
	if (new == NULL)
		return (NULL);
	new->hit = hit_cone;
	new->destroy = destroy_cone;
	new->get_type = get_cone_type;
	if (init_object_arr(&new->faces, 2) == FAILURE)
		return (NULL);
	if (add_object(&new->faces, new_cone_lateral(&co_info->lateral)) == FAILURE
		|| add_object(&new->faces, new_disk(&co_info->disk)) == FAILURE)
		return (NULL);
	return ((t_object *)new);
}

static void	destroy_cone(t_object *object)
{
	t_object_cone	*co;

	co = (t_object_cone *)object;
	clear_object_arr(&co->faces);
	free(co);
}

static int	get_cone_type(void)
{
	return (OBJECT_CONE);
}

/*
	<Line-Cone intersection>

	The cone consists of three faces, one lateral surface and one disk.
	Check the intersection of these faces and line.
*/
static bool	hit_cone(
			t_object *self, t_ray *ray, t_hit_record *h_rec, double t_max)
{
	t_object_cone	*co;

	co = (t_object_cone *)self;
	return (hit_object_arr(&co->faces, ray, h_rec, t_max));
}
