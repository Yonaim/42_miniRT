/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_arr_internal_bonus.h                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:19:21 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/14 10:35:23 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DYNAMIC_ARR_INTERNAL_BONUS_H
# define DYNAMIC_ARR_INTERNAL_BONUS_H

// standard library
# include <stdlib.h>

// user defined library
# include "libft.h"

// structures
# include "s_dynamic_arr_bonus.h"

// extra
# include "constants_bonus.h"
# include "typedef_bonus.h"

int	init_dynamic_arr(t_dynamic_arr *darr, int cap);

#endif