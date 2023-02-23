#ifndef RAY_INTERNAL_H
# define RAY_INTERNAL_H

# include <math.h>
# include "libmath.h"
# include "s_ray.h"
# include "s_camera.h"
# include "s_hit_record.h"

// ray constructor
t_ray		ray(t_point3 origin, t_vector3 dir);

// scattered vectors
t_vector3	reflected_vector(t_vector3 in, t_vector3 n);
t_vector3	refracted_vector(t_vector3 in, t_vector3 n, double idx_ratio);
t_vector3	diffused_vector(t_vector3 n);

#endif