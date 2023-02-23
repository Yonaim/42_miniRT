#ifndef SHADING_INTERNAL_H
# define SHADING_INTERNAL_H

# include <stdbool.h>
# include "libmath.h"
# include "constants.h"
# include "color.h"
# include "s_scene.h"
# include "s_world.h"
# include "camera.h"

t_color3	traced_color(t_ray *ray, t_world *world, int depth);

#endif