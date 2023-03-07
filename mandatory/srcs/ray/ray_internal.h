#ifndef RAY_INTERNAL_H
# define RAY_INTERNAL_H

# include <math.h>
# include "libmath.h"
# include "s_ray.h"
# include "s_camera.h"
# include "s_hit_record.h"
# include "s_scatter_record.h"
# include "s_pdf.h"
# include "pdf.h"

// ray constructor
t_ray		ray(t_point3 origin, t_vector3 dir);
t_vector3	reflected_vector(t_vector3 in, t_vector3 n);

#endif