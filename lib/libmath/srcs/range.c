#include <stdbool.h>

bool	is_in_range(const double n, const double min, const double max)
{
	return (min <= n && n <= max);
}

double	clamp(const double x, const double min, const double max)
{
	if (x < min)
		return (min);
	if (x > max)
		return (max);
	return (x);
}
