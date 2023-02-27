
#ifndef COLOR_H
# define COLOR_H

# include "libmath.h"
# include "typedef.h"

int			color3_to_rgb(t_color3 albedo);
t_color3	rgb_to_color3(unsigned int rgb);

#endif