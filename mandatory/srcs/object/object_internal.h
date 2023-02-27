#ifndef OBJECT_INTERNAL_H
# define OBJECT_INTERNAL_H

# include "libft.h"
# include "libmath.h"
# include "s_object.h"
# include "s_material.h"

enum	e_equation_coefficient
{
	A,
	B,
	C
};

void	set_face_normal(\
		t_hit_record *h_rec, t_ray *in_ray, t_vector3 outward_normal);
bool	determine_t(double *t, double root[2], double t_min, double t_max);

#endif