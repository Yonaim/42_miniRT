#include "color.h"

t_color	color(double r, double g, double b)
{
	return ((t_color)vector3(r, g, b));
}

int	albedo_to_rgb(t_color albedo)
{
	int	r;
	int	g;
	int	b;

	r = 256 * clamp(albedo.x, 0.0, 0.999);
	g = 256 * clamp(albedo.y, 0.0, 0.999);
	b = 256 * clamp(albedo.z, 0.0, 0.999);
	return (r << 16 | g << 8 | b);
}
