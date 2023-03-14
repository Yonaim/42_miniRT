/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_arr_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:18:52 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/05 20:18:52 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DYNAMIC_ARR_BONUS_H
# define DYNAMIC_ARR_BONUS_H

# include "s_dynamic_arr_bonus.h"
# include "typedef_bonus.h"

int				init_dynamic_arr(t_dynamic_arr *darr, int cap);
t_dynamic_arr	*new_dynamic_arr(int cap);
void			clear_dynamic_arr(t_dynamic_arr *darr);
void			destroy_dynamic_arr(t_dynamic_arr *darr);
int				push_back_dynamic_arr(t_dynamic_arr *darr, void *data);

#endif