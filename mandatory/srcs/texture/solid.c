#include "texture_internal.h"

static t_color3	get_solid_val(t_texture *self, double u, double v, t_point3 p);
static int		get_solid_type(void);

t_texture	*new_solid(t_color3 color)
{
	t_texture_solid	*solid;

	solid = malloc(sizeof(t_texture_solid));
	if (!solid)
		return (NULL);
	solid->color = color;
	solid->get_val = get_solid_val;
	solid->get_type = get_solid_type;
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

static int	get_solid_type(void)
{
	return (TEXTURE_SOLID);
}