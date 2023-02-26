
#include <stdbool.h>
#include <math.h>

bool	solve_quadratic(double a, double half_b, double c, double root[2])
{
	double	discr;
	double	sqrt_discr;

	discr = half_b * half_b - a * c;
	if (discr >= 0)
	{
		sqrt_discr = sqrt(discr);
		root[0] = (-half_b - sqrt_discr) / a;
		root[1] = (-half_b + sqrt_discr) / a;
		return (true);
	}
	return (false);
}
