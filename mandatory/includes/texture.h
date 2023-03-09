/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:46:12 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/09 07:30:04 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "s_info_element.h"
# include "typedef.h"

t_texture	*new_texture(const t_info_texture *texture_info);
t_texture	*new_solid(t_color3 rgb);
t_texture	*new_checker_single_solid(t_color3 even);
t_texture	*new_checker_solid(t_color3 even, t_color3 odd);
t_texture	*new_checker(t_texture *even, t_texture *odd);

#endif