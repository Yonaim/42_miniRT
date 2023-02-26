
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
	SCENE1_TWO_CHECKER_BALLS,
	SCENE2_SQUARE_LIGHT,
	SCENE3_CORNELL_BOX
};

typedef t_error	(*t_construct_scene)(t_scene *scene);

t_error	construct_scene0(t_scene *scene);
t_error	construct_scene1(t_scene *scene);
t_error	construct_scene2(t_scene *scene);
t_error	construct_scene3(t_scene *scene);


#endif
