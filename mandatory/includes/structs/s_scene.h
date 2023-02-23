#ifndef S_SCENE_H
# define S_SCENE_H

# include "s_mlx.h"
# include "s_camera.h"
# include "s_world.h"
# include "color.h"

typedef struct s_scene
{
	t_world		world;
	t_camera	cam;
	int			width;
	int			height;
}	t_scene;

#endif