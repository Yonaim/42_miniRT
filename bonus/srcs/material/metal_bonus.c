/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:46:12 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/09 03:58:36 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material_internal_bonus.h"

static bool		metal_scattered(
					t_material *self, t_ray *in,
					t_hit_record *h_rec, t_scatter_record *s_rec);
static t_color3	metal_emitted(
					t_material *self, double u, double v, t_point3 p);
static void		destroy_metal(t_material *self);

t_material	*new_metal(const t_texture *texture, const double fuzz)
{
	t_material_metal	*metal;

	metal = malloc(sizeof(t_material_metal));
	if (!metal)
		return (NULL);
	metal->albedo = (t_texture *)texture;
	metal->fuzz = fuzz;
	metal->scattered = metal_scattered;
	metal->emitted = metal_emitted;
	metal->destroy = destroy_metal;
	return ((t_material *)metal);
}

static bool	metal_scattered(
			t_material *self, t_ray *in,
			t_hit_record *h_rec, t_scatter_record *s_rec)
{
	const t_material_metal	*metal = (t_material_metal *)self;

	s_rec->scattered = reflected_ray(in->dir, h_rec, metal->fuzz);
	s_rec->attenuation = metal->albedo->get_val(\
								metal->albedo, h_rec->u, h_rec->v, h_rec->p);
	if (v3_dot(s_rec->scattered.dir, h_rec->normal) > 0)
		return (true);
	else
		return (false);
}

static t_color3	metal_emitted(
				t_material *self, double u, double v, t_point3 p)
{
	(void)self;
	(void)u;
	(void)v;
	(void)p;
	return (color3(0, 0, 0));
}

static void	destroy_metal(t_material *self)
{
	t_material_metal	*metal;

	metal = (t_material_metal *)self;
	free(metal);
}
