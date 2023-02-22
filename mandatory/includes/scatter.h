#ifndef SCATTER_H
# define SCATTER_H

# include "libmath.h"

// scattered vector constructor
t_vector3	reflect_vector3(t_vector3 in, t_vector3 normal);
t_vector3	refract_vector3(t_vector3 in, t_vector3 normal, double idx_ratio);

#endif