/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_hit_record.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 00:16:49 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/09 03:51:38 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_HIT_RECORD_H
# define S_HIT_RECORD_H

# include <stdbool.h>
# include "libmath.h"
# include "typedef.h"
# include "constants.h"

struct s_hit_record
{
	double		t;
	t_point3	p;
	t_vector3	normal;
	t_onb		onb;
	t_material	*material;
	bool		opposed;
	double		u;
	double		v;
};

#endif