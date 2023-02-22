
#ifndef COLOR_H
# define COLOR_H

# include "libmath.h"

typedef t_vector3	t_color;

int		albedo_to_rgb(t_color albedo);
t_color	background_color(void);

#endif