#ifndef SCATTER_H
# define SCATTER_H

# include "libmath.h"

// scattered vector constructor
t_vector	reflect_vector(t_vector in, t_vector normal);
t_vector	refract_vector(t_vector in, t_vector normal, double idx_ratio);

#endif