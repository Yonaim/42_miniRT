/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_scene.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 00:16:49 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/01 00:16:49 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_SCENE_H
# define S_SCENE_H

# include "typedef.h"
# include "s_world.h"
# include "s_camera.h"

struct s_scene
{
	t_world		world;
	t_camera	cam;
	t_image		*img;
};

#endif