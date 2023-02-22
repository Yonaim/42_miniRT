
#include "quadratic.h"

t_quad_sol	solve_quadratic(double a, double half_b, double c)
{
	t_quad_sol	quad_sol;

	quad_sol.d = half_b * half_b - a * c;
	if (quad_sol.d >= 0)
	{
		quad_sol.sqrt_d = sqrt(quad_sol.d);
		quad_sol.sol1 = (-half_b - quad_sol.sqrt_d) / a;
		quad_sol.sol2 = (-half_b + quad_sol.sqrt_d) / a;
	}
	return (quad_sol);
}
