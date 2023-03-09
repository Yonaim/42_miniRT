/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_random_material.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:19:21 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/09 09:09:11 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material_internal.h"

static t_material	*random_lambertian(void);
static t_material	*random_metal(void);
static t_material	*random_dielectric(void);

t_material	*new_random_material(void)
{
	double	rullet;

	rullet = random_double();
	if (rullet < 0.5)
		return (random_lambertian());
	else if (rullet < 0.8)
		return (random_metal());
	else
		return (random_dielectric());
}

static t_material	*random_lambertian(void)
{
	t_color3	color;
	t_texture	*texture;

	color = v3_random(0, 255);
	texture = new_solid(color);
	return (new_lambertian(texture));
}

static t_material	*random_metal(void)
{
	t_info_texture	info_texture;
	t_texture		*texture;
	double			fuzz;

	info_texture.type = TEXTURE_SOLID;
	info_texture.rgb1 = v3_random(150, 255);
	texture = new_texture(&info_texture);
	fuzz = random_double_range(0, 0.5);
	return (new_metal(texture, fuzz));
}

static t_material	*random_dielectric(void)
{
	return (new_dielectric(1.5));
}
