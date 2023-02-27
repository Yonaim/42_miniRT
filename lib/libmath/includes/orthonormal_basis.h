#ifndef ORTHONORMAL_BASIS_H
# define ORTHONORMAL_BASIS_H

# include "vector3.h"

typedef struct s_orthonormal_basis
{
	t_vector3	u;
	t_vector3	v;
	t_vector3	w;
}	t_orthonormal_basis;

typedef t_orthonormal_basis	t_onb;

#endif