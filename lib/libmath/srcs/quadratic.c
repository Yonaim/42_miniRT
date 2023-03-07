#include <math.h>
#include <stdbool.h>

bool	solve_quadratic(
		const double a, const double b, const double c, double root[2])
{
	const double	half_b = b / 2;
	const double	d = half_b * half_b - a * c;
	double			sqrt_d;

	if (fabs(a) < 1e-8 || d < 0)
		return (false);
	sqrt_d = sqrt(d);
	root[0] = (-half_b - sqrt_d) / a;
	root[1] = (-half_b + sqrt_d) / a;
	return (true);
}

bool	solve_quadratic_half_b(
		const double a, const double half_b, const double c, double root[2])
{
	const double	d = half_b * half_b - a * c;
	double			sqrt_d;

	if (fabs(a) < 1e-8 || d < 0)
		return (false);
	sqrt_d = sqrt(d);
	root[0] = (-half_b - sqrt_d) / a;
	root[1] = (-half_b + sqrt_d) / a;
	return (true);
}
