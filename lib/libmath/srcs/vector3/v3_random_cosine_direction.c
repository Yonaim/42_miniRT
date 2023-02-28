#define __USE_MISC
#include <math.h>
#include "vector3.h"
#include "random.h"

// polar angle : 편각
// azimuthal angle : 방위각
t_vector3	v3_random_cosine_direction(void)
{
	const double	random1 = random_double();
	const double	random2 = random_double();
	const double	cosine_polar = sqrt(1 - random2);
	const double	sine_polar = sqrt(random2);
	const double	azimuthal = 2 * M_PI * random1;

	return (vector3(cos(azimuthal) * sine_polar, \
					sin(azimuthal) * sine_polar, \
					cosine_polar));
}
