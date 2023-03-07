#ifndef ORTHONORMAL_BASIS_H
# define ORTHONORMAL_BASIS_H

# include "vector3.h"

// debug
# include <unistd.h>
# include <stdio.h>
# ifndef error_log
# define error_log(fmt, ...) \
    dprintf(STDERR_FILENO, "%-40s[%3d] : %50s : " fmt "\n", \
	__func__, __LINE__, #__VA_ARGS__, ##__VA_ARGS__)
# endif
typedef struct s_orthonormal_basis
{
	t_vector3	u;
	t_vector3	v;
	t_vector3	w;
}	t_orthonormal_basis;

typedef t_orthonormal_basis	t_onb;

#endif