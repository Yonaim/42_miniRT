/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 00:16:49 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/09 07:44:29 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture_internal_bonus.h"

static t_color3	get_checker_val(t_texture *self, \
									double u, double v, t_point3 p);
static void		destroy_checker(t_texture *self);

t_texture	*new_checker_single_solid(t_color3 even)
{
	t_texture_checker	*checker;

	checker = malloc(sizeof(t_texture_checker));
	if (checker == NULL)
		return (NULL);
	checker->get_val = get_checker_val;
	checker->destroy = destroy_checker;
	checker->even = new_solid(even);
	checker->odd = new_solid(color3(1, 1, 1));
	return ((t_texture *)checker);
}

t_texture	*new_checker_solid(t_color3 even, t_color3 odd)
{
	t_texture_checker	*checker;

	checker = malloc(sizeof(t_texture_checker));
	if (checker == NULL)
		return (NULL);
	checker->get_val = get_checker_val;
	checker->destroy = destroy_checker;
	checker->even = new_solid(even);
	checker->odd = new_solid(odd);
	return ((t_texture *)checker);
}

t_texture	*new_checker(t_texture *even, t_texture *odd)
{
	t_texture_checker	*checker;

	checker = malloc(sizeof(t_texture_checker));
	if (checker == NULL)
		return (NULL);
	checker->get_val = get_checker_val;
	checker->destroy = destroy_checker;
	checker->even = even;
	checker->odd = odd;
	return ((t_texture *)checker);
}

static t_color3	get_checker_val(t_texture *self, double u, double v, t_point3 p)
{
	const t_texture_checker	*checker = (t_texture_checker *)self;
	const double			sines = sin(10 * p.x) \
									* sin(10 * p.y) \
									* sin(10 * p.z);

	if (sines < 0)
		return (checker->odd->get_val(checker->odd, u, v, p));
	else
		return (checker->even->get_val(checker->even, u, v, p));
}

static void	destroy_checker(t_texture *self)
{
	t_texture_checker	*checker;

	checker = (t_texture_checker *)self;
	checker->even->destroy(checker->even);
	checker->odd->destroy(checker->odd);
	free(self);
}
