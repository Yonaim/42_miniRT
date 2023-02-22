#ifndef SHADING_INTERNAL_H
# define SHADING_INTERNAL_H

# include <stdbool.h>
# include "libmath.h"
# include "constants.h"
# include "color.h"
# include "s_ray_tracing.h"
# include "s_world.h"
# include "camera.h"

t_color	traced_color(t_ray *ray, t_world *world, int depth);

#endif