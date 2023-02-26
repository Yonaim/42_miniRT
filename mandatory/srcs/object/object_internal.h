#ifndef OBJECT_INTERNAL_H
# define OBJECT_INTERNAL_H

// window
# define __USE_MISC

// standard library
# include <math.h>
// library
# include "libft.h"
# include "libmath.h"
// structure and typedefine
# include "s_material.h"
# include "s_hit_record.h"
# include "s_object.h"
# include "s_ray.h"
# include "constants.h"
# include "typedef.h"
// functions
# include "ray.h"

void	set_face_normal(\
		t_hit_record *h_rec, t_ray *in_ray, t_vector3 outward_normal);

#endif