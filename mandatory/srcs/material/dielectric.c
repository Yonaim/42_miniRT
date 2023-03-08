/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dielectric.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:46:12 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/09 03:58:40 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material_internal.h"

static bool		dielectric_scattered(
					t_material *self, t_ray *in,
					t_hit_record *h_rec, t_scatter_record *s_rec);
static t_color3	dielectric_emitted(
					t_material *self, double u, double v, t_point3 p);
static void		destroy_dielectric(t_material *self);

t_material	*new_dielectric(const double refractive_idx)
{
	t_material_dielectric	*dielectric;

	dielectric = malloc(sizeof(t_material_dielectric));
	if (!dielectric)
		return (NULL);
	dielectric->refractive_idx = refractive_idx;
	dielectric->scattered = dielectric_scattered;
	dielectric->emitted = dielectric_emitted;
	dielectric->destroy = destroy_dielectric;
	return ((t_material *)dielectric);
}

static bool	dielectric_scattered(
			t_material *self, t_ray *in,
			t_hit_record *h_rec, t_scatter_record *s_rec)
{
	const t_material_dielectric	*dielectric = (t_material_dielectric *)self;
	double						refractive_idx_ratio;

	s_rec->attenuation = color3(1, 1, 1);
	if (h_rec->opposed == true)
		refractive_idx_ratio = 1 / dielectric->refractive_idx;
	else
		refractive_idx_ratio = dielectric->refractive_idx;
	s_rec->scattered = refracted_ray(in->dir, h_rec, refractive_idx_ratio);
	return (true);
}

static t_color3	dielectric_emitted(
				t_material *self, double u, double v, t_point3 p)
{
	(void)self;
	(void)u;
	(void)v;
	(void)p;
	return (color3(0, 0, 0));
}

static void	destroy_dielectric(t_material *self)
{
	t_material_dielectric	*dielectric;

	dielectric = (t_material_dielectric *)self;
	free(dielectric);
}
