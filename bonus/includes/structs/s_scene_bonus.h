/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_scene_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 00:16:49 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/01 00:16:49 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_SCENE_BONUS_H
# define S_SCENE_BONUS_H

# include "typedef_bonus.h"
# include "s_world_bonus.h"
# include "s_camera_bonus.h"

struct s_scene
{
	t_world		world;
	t_camera	cam;
	t_image		*img;
};

#endif