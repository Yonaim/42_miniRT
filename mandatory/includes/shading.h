#ifndef SHADING_H
# define SHADING_H

# include "color.h"
# include "s_scene.h"

t_color3	get_pixel_color(t_ray_tracing *rt, int x, int y);

#endif