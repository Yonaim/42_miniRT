#include <math.h>
#include <stdbool.h>

bool	solve_quadratic(double a, double b, double c, double root[2])
{
	const double	half_b = b / 2;
	const double	d =  half_b * half_b - a * c;
	const double	sqrt_d = sqrt(d);

	if (d < 0)
		return (false);
	root[0] = (-half_b - sqrt_d) / a;
	root[1] = (-half_b + sqrt_d) / a;
	return (true);
}

bool	solve_quadratic_half_b(double a, double half_b, double c, double root[2])
{
	const double	d =  half_b * half_b - a * c;
	const double	sqrt_d = sqrt(d);

	if (d < 0)
		return (false);
	root[0] = (-half_b - sqrt_d) / a;
	root[1] = (-half_b + sqrt_d) / a;
	return (true);
}
