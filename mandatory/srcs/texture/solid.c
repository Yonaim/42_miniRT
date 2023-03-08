#include "texture_internal.h"

static t_color3	get_solid_val(t_texture *self, double u, double v, t_point3 p);
static void		destroy_solid(t_texture *self);

t_texture	*new_solid(t_color3 rgb)
{
	t_texture_solid	*solid;

	solid = malloc(sizeof(t_texture_solid));
	if (!solid)
		return (NULL);
	solid->color = v3_div(rgb, 255);
	solid->get_val = get_solid_val;
	solid->destroy = destroy_solid;
	return ((t_texture *)solid);
}

static t_color3	get_solid_val(t_texture *self, double u, double v, t_point3 p)
{
	const t_texture_solid	*solid = (t_texture_solid *)self;

	(void)u;
	(void)v;
	(void)p;
	return (solid->color);
}

static void	destroy_solid(t_texture *self)
{
	t_texture_solid	*solid;

	solid = (t_texture_solid *)self;
	free(solid);
}
