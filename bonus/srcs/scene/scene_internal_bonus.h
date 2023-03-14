/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_internal_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:17:05 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/14 10:38:04 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_INTERNAL_BONUS_H
# define SCENE_INTERNAL_BONUS_H

// standard library
# include <math.h>
// extra
# include "constants_bonus.h"
# include "libft.h"
# include "handle_error_bonus.h"
# include "typedef_bonus.h"
// structures
# include "s_minirt_bonus.h"
# include "s_scene_bonus.h"
# include "s_mlx_bonus.h"
# include "s_hit_record_bonus.h"
# include "s_scatter_record_bonus.h"
# include "s_material_bonus.h"
# include "s_object_bonus.h"
# include "s_ray_bonus.h"
// prototypes
# include "mlx_utils_bonus.h"
# include "ray_bonus.h"
# include "parsing_bonus.h"
# include "camera_bonus.h"
# include "object_arr_bonus.h"
# include "color_bonus.h"
# include "parsing_bonus.h"
# include "dynamic_arr_bonus.h"

void		gamma_correction(t_color3 *color);
t_color3	traced_color(t_ray *in_ray, t_world *world, int depth);
void		get_sampled_color(\
				t_color3 *sampled_color, t_scene *scene, int x, int y);
void		calculate_average_color(\
				t_color3 *stored_color, t_color3 *sampled_color, \
				int stored_cnt);
void		get_stored_color(\
				t_color3 *stored_color, t_image *img, int x, int y);
void		update_stored_color(\
				t_image *img, t_color3 *stored_color, int x, int y);
#endif