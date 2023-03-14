/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_material_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:18:52 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/09 03:51:14 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_MATERIAL_BONUS_H
# define S_MATERIAL_BONUS_H

# include "typedef_bonus.h"

struct s_material
{
	t_scatter			scattered;
	t_emit				emitted;
	t_destroy_material	destroy;
	t_scattering_pdf	s_pdf;
};

struct s_material_lambertian
{
	t_scatter			scattered;
	t_emit				emitted;
	t_destroy_material	destroy;
	t_scattering_pdf	s_pdf;
	t_texture			*albedo;
};

struct s_material_metal
{
	t_scatter			scattered;
	t_emit				emitted;
	t_destroy_material	destroy;
	t_scattering_pdf	s_pdf;
	t_texture			*albedo;
	double				fuzz;
};

struct s_material_dielectric
{
	t_scatter			scattered;
	t_emit				emitted;
	t_destroy_material	destroy;
	t_scattering_pdf	s_pdf;
	double				refractive_idx;
};

struct s_material_emmisive
{
	t_scatter			scattered;
	t_emit				emitted;
	t_destroy_material	destroy;
	t_scattering_pdf	s_pdf;
	t_texture			*emit;
};

#endif