#ifndef SHADING_H
# define SHADING_H

// # include "color.h"
// # include "s_scene.h"
# include "typedef.h"

t_color3	get_pixel_color(t_scene *scene, int x, int y);
t_color3	sampled_color(t_scene *scene, int x, int y);

#endif