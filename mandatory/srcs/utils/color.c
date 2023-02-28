#include "typedef.h"

t_color3	color3(double r, double g, double b)
{
	return ((t_color3)vector3(r, g, b));
}

int	color3_to_rgb(t_color3 albedo)
{
	int	r;
	int	g;
	int	b;

	r = (int)(256 * clamp(albedo.x, 0.0, 0.999)) & 0xff;
	g = (int)(256 * clamp(albedo.y, 0.0, 0.999)) & 0xff;
	b = (int)(256 * clamp(albedo.z, 0.0, 0.999)) & 0xff;
	return (r << 16 | g << 8 | b);
}

t_color3	rgb_to_color3(unsigned int rgb)
{
	t_color3	color;

	color.x = (double)((rgb >> 16) & 0xff) / 256;
	color.y = (double)((rgb >> 8) & 0xff) / 256;
	color.z = (double)(rgb & 0xff) / 256;
	return (color);
}
