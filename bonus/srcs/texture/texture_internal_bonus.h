/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_internal_bonus.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:19:21 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/09 07:31:26 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_INTERNAL_BONUS_H
# define TEXTURE_INTERNAL_BONUS_H

// standard library
# include <stdlib.h>
# include <math.h>

// structures
# include "typedef_bonus.h"
# include "s_texture_bonus.h"

// functions
t_texture	*new_solid(t_color3 color);
t_texture	*new_checker_solid(t_color3 even, t_color3 odd);
t_texture	*new_checker_single_solid(t_color3 even);

#endif