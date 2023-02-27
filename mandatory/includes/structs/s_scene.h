#ifndef S_SCENE_H
# define S_SCENE_H

# include "typedef.h"
# include "s_world.h"
# include "s_camera.h"

struct s_scene
{
	t_world		world;
	t_camera	cam;
	t_image		*img;
};

#endif