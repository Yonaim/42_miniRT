#ifndef LIBMATH_H
# define LIBMATH_H

/*-------------- USER DEFINED HEADERS ------------*/

# include "vector3.h"
# include "orthonormal_basis.h"

/*------------- STRUCT DECLARATIONS --------------*/

// vector constructor
t_vector3	vector3(const double x, const double y, const double z);
t_point3	point3(const double x, const double y, const double z);
t_point3	color3(const double x, const double y, const double z);

// basic operator
t_vector3	v3_add(const t_vector3 u, const t_vector3 v);
t_vector3	v3_sub(const t_vector3 u, const t_vector3 v);
t_vector3	v3_mul(const t_vector3 v, const double t);
t_vector3	v3_div(const t_vector3 v, const double t);

// length utils
double		len_v3(const t_vector3 v);
double		len_sqr_v3(const t_vector3 v);
bool		is_near_zero(const t_vector3 v);

// v3_normalize
t_vector3	v3_normalize(const t_vector3 v);

// product
double		v3_dot(const t_vector3 u, const t_vector3 v);
t_vector3	v3_cross(const t_vector3 u, const t_vector3 v);
t_vector3	v3_comp_wise(const t_vector3 u, const t_vector3 v);

// random vector
t_vector3	v3_random(const double min, const double max);
t_vector3	v3_random_in_unit_sphere(void);
t_vector3	v3_random_in_sphere(double radius);
t_vector3	v3_random_on_unit_sphere(void);
t_vector3	v3_random_on_sphere(double radius);
t_vector3	v3_random_in_unit_disk(void);
t_vector3	v3_random_in_disk(double radius);
t_vector3	v3_random_on_unit_disk(void);
t_vector3	v3_random_on_disk(double radius);
t_vector3	v3_random_cosine_direction(void);

// discriminant
bool		solve_quadratic(
				const double a, const double b, const double c, double root[2]);
bool		solve_quadratic_half_b(
				const double a, const double half_b, const double c, double root[2]);

// range
bool		is_in_range(const double n, const double min, const double max);
double		clamp(const double x, const double min, const double max);

// trigonometry
double		degree_to_radian(const double degrees);

// random
double		random_double(void);
double		random_double_range(const double min, const double max);
int			random_int_range(int min, int max);

// orthonormal basis
void		build_onb_from_w(t_onb *onb, const t_vector3 *n);
void		transform_to_onb(\
			const t_onb *onb, const t_vector3 *in_vec, t_vector3 *out_vec);
void		transform_to_onb_in_place(const t_onb *onb, t_vector3 *in_vec);

// swap
void		swap_int(int *num_1, int *num_2);
void		swap_double(double *num_1, double *num_2);

#endif
