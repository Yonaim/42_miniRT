/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:18:52 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/09 03:29:17 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	ft_atof_fractional_part(char *str)
{
	double	n;
	double	unit_n;

	n = 0;
	unit_n = 0.1;
	while (ft_isdigit(*str))
	{
		n += unit_n * (*str - '0');
		unit_n /= 10;
		str++;
	}
	return (n);
}

double	ft_atof(char *str)
{
	int		point_left;
	double	point_right;

	point_left = ft_atoi(str);
	point_right = 0;
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
		str++;
	if (*str == '.')
		point_right = ft_atof_fractional_part(++str);
	if (point_left < 0)
		return ((double)(point_left + (point_right * -1)));
	else
		return ((double)(point_left + point_right));
}
