#ifndef LIBMATH_H
# define LIBMATH_H

# include "vector3.h"
# include "quadratic.h"

// vector constructor
t_vector	vector(double x, double y, double z);
t_point		point(double x, double y, double z);
t_point		color(double x, double y, double z);

// basic operator
t_vector	v_add(t_vector u, t_vector v);
t_vector	v_sub(t_vector u, t_vector v);
t_vector	v_mul(t_vector v, double t);
t_vector	v_div(t_vector v, double t);

// length utils
double		len_v(t_vector v);
double		len_sqr_v(t_vector v);
bool		is_near_zero(t_vector v);

// normalize
t_vector	v_normalize(t_vector v);

// product
double		v_dot(t_vector u, t_vector v);
t_vector	v_cross(t_vector u, t_vector v);
t_vector	v_componentwise(t_vector u, t_vector v);

// random vector
t_vector	v_random(double min, double max);
t_vector	v_random_in_unit_sphere(void);
t_vector	v_random_on_unit_sphere(void);
t_vector	v_random_in_unit_disk(void);
t_vector	v_random_on_unit_disk(void);

// discriminant
t_discr		solve_quadratic(double a, double b, double c);

#endif
