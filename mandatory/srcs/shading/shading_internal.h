#ifndef SHADING_INTERNAL_H
# define SHADING_INTERNAL_H

// standard library
# include <stdbool.h>
# include <math.h>

// user defined library
# include "libmath.h"
# include "libft.h"

// user defined header files
# include "constants.h"
# include "typedef.h"
# include "s_object.h"
# include "s_object_arr.h"
# include "s_material.h"
# include "s_hit_record.h"
# include "s_scatter_record.h"
# include "s_scene.h"
# include "object_arr.h"
# include "color.h"
# include "camera.h"

t_color3	traced_color(t_ray *ray, t_world *world, int depth);

#endif