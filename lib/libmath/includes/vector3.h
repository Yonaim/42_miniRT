
#ifndef VECTOR3_H
# define VECTOR3_H

/*--------------- STANDARD HEADERS ---------------*/

# include <stdbool.h>

/*------------ DEFINE MACRO CONSTANTS ------------*/

# define EPSILON 1e-8

/*------------- STRUCT DECLARATIONS --------------*/

typedef struct s_vector3
{
	double	x;
	double	y;
	double	z;
}	t_vector3;

typedef t_vector3	t_point3;

/*-------------- FUNCTION PROTOTYPES -------------*/

// vector constructor
t_vector3	vector3(double x, double y, double z);
t_point3	point3(double x, double y, double z);
t_point3	color3(double x, double y, double z);

// basic operator
t_vector3	v3_add(t_vector3 u, t_vector3 v);
t_vector3	v3_sub(t_vector3 u, t_vector3 v);
t_vector3	v3_mul(t_vector3 v, double t);
t_vector3	v3_div(t_vector3 v, double t);

// length utils
double		len_v3(t_vector3 v);
double		len_sqr_v3(t_vector3 v);
bool		is_near_zero(t_vector3 v);

// v3_normalize
t_vector3	v3_normalize(t_vector3 v);

// product
double		v3_dot(t_vector3 u, t_vector3 v);
t_vector3	v3_cross(t_vector3 u, t_vector3 v);
t_vector3	v3_comp_wise(t_vector3 u, t_vector3 v);

// random vector
t_vector3	v3_random(double min, double max);
t_vector3	v3_random_in_unit_sphere(void);
t_vector3	v3_random_on_unit_sphere(void);
t_vector3	v3_random_in_unit_disk(void);
t_vector3	v3_random_on_unit_disk(void);

#endif
