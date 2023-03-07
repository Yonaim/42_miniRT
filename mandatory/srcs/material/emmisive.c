#include "material_internal.h"

static void		destroy_emmisive(t_material *self);
static bool		emmisive_emit(
					t_material *self, t_hit_record *h_rec, t_color3 *emission);
static bool		emmisive_scatter(
					t_material *self, t_ray *in, 
					t_hit_record *h_rec, t_scatter_record *s_rec);
static int		get_emmisive_type(void);

t_material	*new_emmisive(t_color3 color)
{
	t_material_emmisive	*emmisive;

	emmisive = malloc(sizeof(t_material_emmisive));
	if (!emmisive)
		return (NULL);
	emmisive->destroy = destroy_emmisive;
	emmisive->emit = emmisive_emit;
	emmisive->scatter = emmisive_scatter;
	emmisive->get_type = get_emmisive_type;
	emmisive->emission = new_solid(color);
	return ((t_material *)emmisive);
}

static void	destroy_emmisive(t_material *self)
{
	t_material_emmisive	*emmisive;

	emmisive = (t_material_emmisive *)self;
	emmisive->emission->destroy(emmisive->emission);
	free(emmisive);
}

/**
 * For the emissive object, only the front surface of the object emits light 
 * and the interior does not emission light.
*/
static bool	emmisive_emit(
			t_material *self, t_hit_record *h_rec, t_color3 *emission)
{
	const t_texture	*texture= ((t_material_emmisive *)self)->emission;

	if (h_rec->opposed == false)
		*emission = color3(0, 0, 0);
	*emission = texture->get_val(texture, h_rec);
	return (true);
}

static bool	emmisive_scatter(
			t_material *self, t_ray *in,
			t_hit_record *h_rec, t_scatter_record *s_rec)
{
	(void)self;
	(void)in;
	(void)h_rec;
	(void)s_rec;
	return (false);
}

static int	get_emmisive_type(void)
{
	return (MATERIAL_EMMISIVE);
}
 