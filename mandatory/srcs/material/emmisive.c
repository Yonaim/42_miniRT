#include "material_internal.h"

static bool		emmisive_scattered(
					t_material *self, t_ray *in, 
					t_hit_record *h_rec, t_scatter_record *s_rec);
static t_color3	emmisive_emitted(t_material *self, t_hit_record *h_rec);
static void		destroy_emmisive(t_material *self);
static int		get_emmisive_type(void);

t_material	*new_emmisive(t_color3 color)
{
	t_material_emmisive	*emmisive;

	emmisive = malloc(sizeof(t_material_emmisive));
	if (!emmisive)
		return (NULL);
	emmisive->destroy = destroy_emmisive;
	emmisive->emitted = emmisive_emitted;
	emmisive->scattered = emmisive_scattered;
	emmisive->get_type = get_emmisive_type;
	emmisive->emit = new_solid(color);
	return ((t_material *)emmisive);
}

static bool	emmisive_scattered(
			t_material *self, t_ray *in,
			t_hit_record *h_rec, t_scatter_record *s_rec)
{
	(void)self;
	(void)in;
	(void)h_rec;
	(void)s_rec;
	return (false);
}

/**
 * For the emissive object, only the front surface of the object emits light 
 * and the interior does not emit light.
*/
static t_color3	emmisive_emitted(t_material *self, t_hit_record *h_rec)
{
	t_material_emmisive	*emmisive;
	t_color3			emitted;

	emmisive = (t_material_emmisive *)self;
	if (h_rec->opposed == false)
		return (color3(0, 0, 0));
	emitted = emmisive->emit->get_val(\
								emmisive->emit, h_rec->u, h_rec->v, h_rec->p);
	return (emitted);
}

static void	destroy_emmisive(t_material *self)
{
	t_material_emmisive	*emmisive;
	
	emmisive = (t_material_emmisive *)self;
	emmisive->emit->destroy(emmisive->emit);
	free(emmisive);
}

static int	get_emmisive_type(void)
{
	return (MATERIAL_EMMISIVE);
}
 