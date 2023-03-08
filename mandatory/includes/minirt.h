/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 00:16:49 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/09 03:53:30 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

// # include "s_scene.h"
# include "constants.h"
# include "typedef.h"
# include "handle_error.h"
# include "s_minirt.h"
# include "s_mlx.h"
# include "s_scene.h"
# include "color.h"
# include "camera.h"
# include "mlx_utils.h"
# include "scene.h"

int	parse_scene(t_scene *scene, char *path);

#endif
