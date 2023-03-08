/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   must_be_element.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:18:52 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/09 03:45:01 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_internal.h"

bool	is_must_be_one_element_type(int type)
{
	const int	must_be_one[] = {
		ELEMENT_AMBIENT,
		ELEMENT_CAMERA,
		ELEMENT_NONE
	};
	int			i;

	i = 0;
	while (must_be_one[i] != ELEMENT_NONE)
	{
		if (type == must_be_one[i])
			return (true);
		i++;
	}
	return (false);
}

bool	is_must_be_elements_exist(bool elem_exist[])
{
	int	i;

	i = 0;
	while (i < ELEMENT_TYPE_COUNT)
	{
		if (is_must_be_one_element_type(i) == true \
			&& elem_exist[i] == 0)
			return (false);
		i++;
	}
	return (true);
}
