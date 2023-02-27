#include <stdbool.h>

bool	is_in_range(double n, double min, double max)
{
	return (min <= n && n <= max);
}

double	clamp(double x, double min, double max)
{
	if (x < min)
		return (min);
	if (x > max)
		return (max);
	return (x);
}
