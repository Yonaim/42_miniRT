#include <stdio.h>
#include <math.h>
#include "typedef.h"

t_color3	color3(double r, double g, double b)
{
	return ((t_color3)vector3(r, g, b));
}

int	albedo_to_rgb(t_color3 albedo)
{
	int	r;
	int	g;
	int	b;

	r = 256 * clamp(albedo.x, 0.0, 0.999);
	g = 256 * clamp(albedo.y, 0.0, 0.999);
	b = 256 * clamp(albedo.z, 0.0, 0.999);
	return (r << 16 | g << 8 | b);
}

void	write_color(t_color3 pixel_color)
{
	printf("%d %d %d\n", (int)(256 * clamp(pixel_color.x, 0.0, 0.999)), \
						(int)(256 * clamp(pixel_color.y, 0.0, 0.999)), \
						(int)(256 * clamp(pixel_color.z, 0.0, 0.999)));
}
