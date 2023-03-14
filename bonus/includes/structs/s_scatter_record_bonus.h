/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_scatter_record_bonus.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 00:16:49 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/09 03:51:09 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_SCATTER_RECORD_BONUS_H
# define S_SCATTER_RECORD_BONUS_H

# include <stdbool.h>
# include "typedef_bonus.h"
# include "s_ray_bonus.h"
// pdf = probability density function

struct s_scatter_record
{
	bool		is_specular;
	t_ray		scattered;
	t_color3	attenuation;
	t_ray		specular_ray;
	double		pdf_val;
};

#endif