/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:19:21 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/09 07:31:26 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_INTERNAL_H
# define TEXTURE_INTERNAL_H

// standard library
# include <stdlib.h>
# include <math.h>

// structures
# include "typedef.h"
# include "s_texture.h"

// functions
t_texture	*new_solid(t_color3 color);
t_texture	*new_checker_solid(t_color3 even, t_color3 odd);
t_texture	*new_checker_single_solid(t_color3 even);

#endif