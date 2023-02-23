#ifndef SHADING_H
# define SHADING_H

# include "color.h"
# include "s_ray_tracing.h"

t_color	get_pixel_color(t_ray_tracing *rt, int x, int y);

#endif