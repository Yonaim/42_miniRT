
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

t_error	construct_world(t_world *world);

#endif
