/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xz_rectangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:18:43 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/05 22:00:59 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object_internal.h"

static void	destroy_xz_rectangle(t_object *self);
static int	get_xz_rectangle_type(void);
static bool	hit_xz_rectangle(
				t_object *self,
				t_ray *ray, t_hit_record *h_rec, double t_max);

t_object	*new_xz_rectangle(t_info_object_xz_rectangle *xz_rec_info)
{
	t_object_xz_rectangle	*new;

	new = malloc(sizeof(t_object_xz_rectangle));
	if (new == NULL)
		return (NULL);
	new->destroy = destroy_xz_rectangle;
	new->get_type = get_xz_rectangle_type;
	new->hit = hit_xz_rectangle;
	new->material = new_material(&xz_rec_info->material);
	if (new->material == NULL)
		return (NULL);
	if (xz_rec_info->x1 > xz_rec_info->x2)
		swap_double_value(&xz_rec_info->x1, &xz_rec_info->x2);
	if (xz_rec_info->z1 > xz_rec_info->z2)
		swap_double_value(&xz_rec_info->z1, &xz_rec_info->z2);
	new->x1 = xz_rec_info->x1;
	new->x2 = xz_rec_info->x2;
	new->z1 = xz_rec_info->z1;
	new->z2 = xz_rec_info->z2;
	new->y = xz_rec_info->y;
	return ((t_object *)new);
}

static void	destroy_xz_rectangle(t_object *self)
{
	t_object_xz_rectangle	*rectangle;

	rectangle = (t_object_xz_rectangle *)self;
	rectangle->material->destroy(rectangle->material);
	free(rectangle);
}

static bool	hit_xz_rectangle(
			t_object *self, t_ray *in_ray, t_hit_record *h_rec, double t_max)
{
	const t_object_xz_rectangle	*rc = (t_object_xz_rectangle *)self;
	const double				t = (rc->y - in_ray->origin.y) / in_ray->dir.y;
	double						x;
	double						z;

	if (t < T_MINIMUM || t > t_max)
		return (false);
	x = in_ray->origin.x + t * in_ray->dir.x;
	z = in_ray->origin.z + t * in_ray->dir.z;
	if (x < rc->x1 || x > rc->x2 || z < rc->z1 || z > rc->z2)
		return (false);
	h_rec->u = (x - rc->x1) / (rc->x2 - rc->x1);
	h_rec->v = (z - rc->z1) / (rc->z2 - rc->z1);
	h_rec->t = t;
	h_rec->material = rc->material;
	h_rec->p = ray_at(in_ray, (double)t);
	set_face_normal(h_rec, in_ray, vector3(0, 1, 0));
	return (true);
}

static int	get_xz_rectangle_type(void)
{
	return (OBJECT_XZ_RECTANGLE);
}
