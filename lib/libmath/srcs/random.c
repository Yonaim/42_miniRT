
#include <limits.h>
#define __USE_MISC
#define RANDOM_SEED 2
#include <math.h>
#include "vector3.h"

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

// pdf가 cosine에 비례하도록 random unit vector 선택
t_vector3	random_cosine_dir(void)
{
	const double	random1 = random_double();
	const double	random2 = random_double();
	const double	phi = 2 * M_PI * random1;
	const double	sin_theta = sqrt(random2);
	double			pos[3];

	pos[0] = cos(phi) * sin_theta;
	pos[1] = sin(phi) * sin_theta;
	pos[2] = sqrt(1 - random2);
	return (vector3(pos[0], pos[1], pos[2]));
}
