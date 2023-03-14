/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 00:16:49 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/14 10:38:04 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_BONUS_H
# define MINIRT_BONUS_H

// # include "s_scene_bonus.h"
# include "constants_bonus.h"
# include "typedef_bonus.h"
# include "handle_error_bonus.h"
# include "s_minirt_bonus.h"
# include "s_mlx_bonus.h"
# include "s_scene_bonus.h"
# include "color_bonus.h"
# include "camera_bonus.h"
# include "mlx_utils_bonus.h"
# include "scene_bonus.h"

int	parse_scene(t_scene *scene, char *path);

#endif
