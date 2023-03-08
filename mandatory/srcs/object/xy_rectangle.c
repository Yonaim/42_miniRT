/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xy_rectangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:18:43 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/05 22:00:53 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object_internal.h"

static void	destroy_xy_rectangle(t_object *self);
static int	get_xy_rectangle_type(void);
static bool	hit_xy_rectangle(
				t_object *self,
				t_ray *ray, t_hit_record *h_rec, double t_max);

// TODO : x1 > x2 또는 y1 > y2인 경우에 대한 처리 추가
t_object	*new_xy_rectangle(t_info_object_xy_rectangle *xy_rec_info)
{
	t_object_xy_rectangle	*new;

	new = malloc(sizeof(t_object_xy_rectangle));
	if (!new)
		return (NULL);
	new->destroy = destroy_xy_rectangle;
	new->get_type = get_xy_rectangle_type;
	new->hit = hit_xy_rectangle;
	new->material = new_material(&xy_rec_info->material);
	if (new->material == NULL)
		return (NULL);
	if (xy_rec_info->x1 > xy_rec_info->x2)
		swap_double_value(&xy_rec_info->x1, &xy_rec_info->x2);
	if (xy_rec_info->y1 > xy_rec_info->y2)
		swap_double_value(&xy_rec_info->y1, &xy_rec_info->y2);
	new->x1 = xy_rec_info->x1;
	new->x2 = xy_rec_info->x2;
	new->y1 = xy_rec_info->y1;
	new->y2 = xy_rec_info->y2;
	new->z = xy_rec_info->z;
	return ((t_object *)new);
}

static void	destroy_xy_rectangle(t_object *self)
{
	t_object_xy_rectangle	*rectangle;

	rectangle = (t_object_xy_rectangle *)self;
	rectangle->material->destroy(rectangle->material);
	free(rectangle);
}

static bool	hit_xy_rectangle(
			t_object *self, t_ray *in_ray, t_hit_record *h_rec, double t_max)
{
	const t_object_xy_rectangle	*rc = (t_object_xy_rectangle *)self;
	const double				t = (rc->z - in_ray->origin.z) / in_ray->dir.z;
	double						x;
	double						y;

	if (t < T_MINIMUM || t > t_max)
		return (false);
	x = in_ray->origin.x + t * in_ray->dir.x;
	y = in_ray->origin.y + t * in_ray->dir.y;
	if (x < rc->x1 || x > rc->x2 || y < rc->y1 || y > rc->y2)
		return (false);
	h_rec->u = (x - rc->x1) / (rc->x2 - rc->x1);
	h_rec->v = (y - rc->y1) / (rc->y2 - rc->y1);
	h_rec->t = t;
	h_rec->material = rc->material;
	h_rec->p = ray_at(in_ray, (double)t);
	set_face_normal(h_rec, in_ray, vector3(0, 0, 1));
	return (true);
}

static int	get_xy_rectangle_type(void)
{
	return (OBJECT_XY_RECTANGLE);
}
