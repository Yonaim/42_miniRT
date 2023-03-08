/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_world.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:18:52 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/05 20:18:52 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_WORLD_H
# define S_WORLD_H

# include "typedef.h"
# include "s_dynamic_arr.h"

struct s_world
{
	t_object_arr	objects;
	t_color3		background_color;
};

#endif