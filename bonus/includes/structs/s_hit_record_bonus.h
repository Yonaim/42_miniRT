/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_hit_record_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 00:16:49 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/14 10:35:11 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_HIT_RECORD_BONUS_H
# define S_HIT_RECORD_BONUS_H

# include <stdbool.h>
# include "libmath.h"
# include "typedef_bonus.h"
# include "constants_bonus.h"

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