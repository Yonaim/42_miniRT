/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orthonormal_basis.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 00:16:49 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/01 00:16:49 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ORTHONORMAL_BASIS_H
# define ORTHONORMAL_BASIS_H

# include "vector3.h"

typedef struct s_orthonormal_basis
{
	t_vector3	u;
	t_vector3	v;
	t_vector3	w;
}	t_orthonormal_basis;

typedef t_orthonormal_basis	t_onb;

#endif