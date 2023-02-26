#ifndef WORLD_INTERNAL_H
# define WORLD_INTERNAL_H

// standard library
# include <stdlib.h>

// user defined library
# include "libft.h"

// structures
# include "s_world.h"
# include "s_object.h"
# include "s_material.h"
# include "s_texture.h"
# include "typedef.h"

// constants
# include "constants.h"

// functions
t_error	init_object_arr(t_object_arr *objects, int cap);
void	flush_object_arr(t_object_arr *objects);

#endif