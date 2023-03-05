#include "scene_internal.h"

void	gamma_correction(t_color3 *color)
{
	color->x = sqrt(color->x);
	color->y = sqrt(color->y);
	color->z = sqrt(color->z);
}
