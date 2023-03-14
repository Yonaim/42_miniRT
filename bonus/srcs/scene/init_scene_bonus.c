/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:46:12 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/09 03:47:15 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_internal_bonus.h"
#include <fcntl.h>

void	init_scene(t_scene *scene, t_image *img, char *path)
{
	const int	fd = open(path, O_RDONLY);

	if (fd < 0)
		handle_error("open file failed");
	if (init_object_arr(&scene->world.objects, \
								INITIAL_OBJECT_ARR_SIZE) == FAILURE)
		handle_error(ERRMSG_MALLOC_FAILED);
	parse_scene(scene, fd);
	init_camera(&scene->cam);
	scene->img = img;
}
