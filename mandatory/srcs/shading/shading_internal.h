#ifndef SHADING_INTERNAL_H
# define SHADING_INTERNAL_H

// standard library
# include <stdbool.h>

// user defined library
# include "libmath.h"
# include "libft.h"

/*** user defined header files ***/
// extra
# include "constants.h"
# include "typedef.h"
// structures
# include "s_scene.h"
# include "s_mlx.h"
# include "s_object.h"
# include "s_material.h"
# include "s_hit_record.h"
# include "s_scatter_record.h"
// functions
# include "color.h"
# include "camera.h"

t_color3	traced_color(t_ray *ray, t_world *world, int depth);

#endif