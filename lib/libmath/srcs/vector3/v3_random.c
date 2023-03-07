
#include "vector3.h"
#include "random.h"

t_vector3	v3_random(const double min, const double max)
{
	return (vector3(random_double_range(min, max), \
				random_double_range(min, max), \
				random_double_range(min, max)));
}
