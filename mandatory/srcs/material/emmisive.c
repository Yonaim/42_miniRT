#include "material_internal.h"

static bool		emmisive_scattered(\
							t_material *self, t_ray *in, \
							t_hit_record *h_rec, t_scatter_record *s_rec);
static t_color3	emmisive_emitted(\
								t_material *self, \
								double u, double v, t_point3 p);
static void		destroy_emmisive(t_material *self);

t_material	*new_emmisive(t_color3 color)
{
	t_material_emmisive	*emmisive;

	emmisive = malloc(sizeof(t_material_emmisive));
	if (!emmisive)
		return (NULL);
	emmisive->emit = new_solid(color);
	emmisive->scattered = emmisive_scattered;
	emmisive->emitted = emmisive_emitted;
	emmisive->destroy = destroy_emmisive;
	return ((t_material *)emmisive);
}

static bool	emmisive_scattered(\
							t_material *self, t_ray *in, \
							t_hit_record *h_rec, t_scatter_record *s_rec)
{
	(void)self;
	(void)in;
	(void)h_rec;
	(void)s_rec;
	return (false);
}

static t_color3	emmisive_emitted(\
								t_material *self, \
								double u, double v, t_point3 p)
{
	t_material_emmisive	*emmisive;
	t_color3			emitted;

	emmisive = (t_material_emmisive *)self;
	emitted = emmisive->emit->get_val(emmisive->emit, u, v, p);
	return (emitted);
}

static void	destroy_emmisive(t_material *self)
{
	t_material_emmisive	*emmisive;

	emmisive = (t_material_emmisive *)self;
	emmisive->emit->destroy(emmisive->emit);
	free(emmisive);
}
