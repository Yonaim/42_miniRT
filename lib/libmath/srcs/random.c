
#include <limits.h>

static int	xorshift(void)
{
	static int	seed = 1;

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

double	random_double_range(const double min, const double max)
{
	return (min + (max - min) * random_double());
}

int		random_int(void)
{
	return (xorshift());
}

int	random_int_range(const int min, const int max)
{
	if (min == max)
		return (min);
	return (random_int() % (max - min + 1) + min);
}
