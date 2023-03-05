#ifndef TEXTURE_INTERNAL_H
# define TEXTURE_INTERNAL_H

// standard library
# include <stdlib.h>
# include <math.h>

// structures
# include "typedef.h"
# include "s_texture.h"

// functions
t_texture	*new_solid(t_color3 color);
t_texture	*new_checker_solid(t_color3 even, t_color3 odd);

#endif