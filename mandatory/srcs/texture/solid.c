#include "texture_internal.h"

static t_color3	get_solid_val(
					const t_texture *self,
					const t_hit_record *h_rec);
static void		destroy_solid(t_texture *self);

t_texture	*new_solid(t_color3 rgb)
{
	t_texture_solid	*solid;

	solid = malloc(sizeof(t_texture_solid));
	if (!solid)
		return (NULL);
	solid->color = v3_div(rgb, 256);
	solid->get_val = get_solid_val;
	solid->destroy = destroy_solid;
	return ((t_texture *)solid);
}

static t_color3	get_solid_val(
				const t_texture *self,
				const t_hit_record *h_rec)
{
	const t_texture_solid	*solid = (t_texture_solid *)self;

	(void)h_rec;
	return (solid->color);
}

static void	destroy_solid(t_texture *self)
{
	t_texture_solid	*solid;

	solid = (t_texture_solid *)self;
	free(solid);
}