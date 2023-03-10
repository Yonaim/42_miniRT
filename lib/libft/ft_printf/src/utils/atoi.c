/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:40:42 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/09 04:02:33 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	fmt_atoi(const char **str)
{
	int	n;

	n = 0;
	while ('0' <= **str && **str <= '9')
	{
		n *= 10;
		n += **str - '0';
		(*str)++;
	}
	return (n);
}
