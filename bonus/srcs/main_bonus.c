/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:19:21 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/07 22:45:19 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

static void	init_renderer(t_minirt *minirt, char *path)
{
	init_mlx(&minirt->mlx);
	init_scene(&minirt->scene, &minirt->mlx.img, path);
}

int	main(int argc, char *argv[])
{
	t_minirt	minirt;

	if (argc != 2)
		return (handle_error(ERRMSG_ARG_CNT));
	init_renderer(&minirt, argv[1]);
	mlx_hook(minirt.mlx.win, EVENT_KEY_PRESS, 0, keypress_hook, &minirt);
	mlx_hook(minirt.mlx.win, EVENT_DESTROY, 0, destroy_hook, &minirt);
	mlx_loop_hook(minirt.mlx.conn, render_scene, &minirt);
	mlx_loop(minirt.mlx.conn);
	return (0);
}
