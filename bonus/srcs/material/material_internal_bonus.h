/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_internal_bonus.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:46:12 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/14 10:35:11 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_INTERNAL_BONUS_H
# define MATERIAL_INTERNAL_BONUS_H

# define __USE_MISC

// standard library
# include <stdbool.h>
# include <math.h>
# include <stdlib.h>

// user defined library
# include "libmath.h"

// structure
# include "typedef_bonus.h"
# include "s_scatter_record_bonus.h"
# include "s_hit_record_bonus.h"
# include "s_material_bonus.h"
# include "s_texture_bonus.h"

// prototype
# include "ray_bonus.h"
# include "texture_bonus.h"

t_material	*new_lambertian(const t_texture *texture);
t_material	*new_dielectric(const double refractive_idx);
t_material	*new_metal(const t_texture *texture, const double fuzz);
t_material	*new_emmisive(const t_color3 color);
t_material	*new_random_material(void);

#endif