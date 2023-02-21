
#ifndef COLOR_H
# define COLOR_H

#include "libmath.h"

typedef t_vector	t_color;

void	write_color(t_color pixel_color, int samples_per_pixel);
t_color	background_color(void);


#endif