
#include <limits.h>
#include "random.h"

int	xorshift(void)
{
	static int	seed = RANDOM_SEED;

	seed ^= seed << 13;
	seed ^= seed >> 17;
	seed ^= seed << 5;
	if (seed < 0)
		return (~seed + 1);
	else
		return (seed);
}

double	random_double(void)
{
	return (xorshift() / (INT_MAX + 1.0));
}

double	random_double_range(double min, double max)
{
	return (min + (max - min) * random_double());
}
