#ifndef OBJECT_ARR_INTERNAL_H
# define OBJECT_ARR_INTERNAL_H

// standard library
# include <stdlib.h>

// user defined library
# include "libft.h"

// structures
# include "s_world.h"
# include "s_dynamic_arr.h"
# include "s_object.h"
# include "s_material.h"
# include "s_texture.h"
# include "s_hit_record.h"
# include "typedef.h"

// declaration
# include "dynamic_arr.h"
# include "pdf.h"

// constants
# include "constants.h"

t_object	*get_object(t_object_arr *object_arr, int idx);

#endif