/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:19:21 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/14 10:38:04 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"
#include "constants.h"
#include "s_mlx_bonus.h"
#include "s_minirt.h"
#include "mlx_utils.h"
#include "scene.h"
#include "color.h"

int	destroy_hook(void *minirt)
{
	flush_scene(&((t_minirt *)minirt)->scene);
	exit(0);
}

int	keypress_hook(int keycode, void *minirt)
{
	if (keycode == KEY_ESC)
	{
		flush_scene(&((t_minirt *)minirt)->scene);
		exit(0);
	}
	return (0);
}
