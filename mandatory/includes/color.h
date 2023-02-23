
#ifndef COLOR_H
# define COLOR_H

# include "libmath.h"

typedef t_vector3	t_color3;

int			albedo_to_rgb(t_color3 albedo);
t_color3	background_color(void);

#endif