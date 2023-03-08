/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_arr_internal.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:19:21 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/09 04:14:34 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DYNAMIC_ARR_INTERNAL_H
# define DYNAMIC_ARR_INTERNAL_H

// standard library
# include <stdlib.h>

// user defined library
# include "libft.h"

// structures
# include "s_dynamic_arr.h"

// extra
# include "constants.h"
# include "typedef.h"

int	init_dynamic_arr(t_dynamic_arr *darr, int cap);

#endif