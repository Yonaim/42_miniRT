#ifndef S_SCENE_H
# define S_SCENE_H

# include "typedef.h"

struct s_scene
{
	t_world		world;
	t_camera	cam;
	int			width;
	int			height;
};

#endif