
#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>

# include "s_scene.h"
# include "constants.h"
# include "typedef.h"
# include "error.h"
# include "color.h"
# include "camera.h"
# include "shading.h"
# include "world.h"

enum e_scene_number
{
	SCENE0_MANY_BALLS,
	SCENE1_TWO_CHECKER_BALLS
};

typedef t_error	(*t_construct_scene)(t_world *world, t_camera *cam);

t_error	construct_scene0(t_world *world, t_camera *cam);
t_error	construct_scene1(t_world *world, t_camera *cam);


#endif
