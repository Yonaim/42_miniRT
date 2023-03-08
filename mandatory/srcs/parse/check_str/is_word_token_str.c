/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_word_token_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:18:52 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/09 03:43:17 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_internal.h"
#include <stdbool.h>

bool	is_number_str(char *s)
{
	while (*s == ' ' || *s == '\t')
		s++;
	if (*s == '+' || *s == '-')
		s++;
	if (ft_isdigit(*s) == false)
		return (false);
	while (ft_isdigit(*s) == true)
		s++;
	if (*s == '.')
	{
		s++;
		if (ft_isdigit(*s) == false)
			return (false);
		while (ft_isdigit(*s) == true)
			s++;
	}
	if (*s == '\0')
		return (true);
	return (false);
}
