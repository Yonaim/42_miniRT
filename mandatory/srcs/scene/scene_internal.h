#ifndef SCENE_INTERNAL_H
# define SCENE_INTERNAL_H

# include "constants.h"
# include "handle_error.h"
# include "typedef.h"
// structures
# include "s_scene.h"
# include "s_mlx.h"
# include "s_hit_record.h"
# include "s_scatter_record.h"
# include "s_material.h"
# include "s_object.h"
# include "s_ray.h"
// prototypes
# include "mlx_utils.h"
# include "ray.h"

t_color3	sampled_color(t_scene *scene, int x, int y);

#endif