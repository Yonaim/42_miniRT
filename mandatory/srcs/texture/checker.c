#include "texture_internal.h"

static t_color3	get_checker_val(
					const t_texture *self, 	const t_hit_record *h_rec);
static void		destroy_checker(t_texture *self);

t_texture	*new_checker_solid(t_color3 even, t_color3 odd)
{
	t_texture_checker	*checker;

	checker = malloc(sizeof(t_texture_checker));
	if (checker == NULL)
		return (NULL);
	checker->get_val = get_checker_val;
	checker->destroy = destroy_checker;
	checker->even = new_solid(even);
	checker->odd = new_solid(odd);
	return ((t_texture *)checker);
}

t_texture	*new_checker(t_texture *even, t_texture *odd)
{
	t_texture_checker	*checker;

	checker = malloc(sizeof(t_texture_checker));
	if (checker == NULL)
		return (NULL);
	checker->get_val = get_checker_val;
	checker->destroy = destroy_checker;
	checker->even = even;
	checker->odd = odd;
	return ((t_texture *)checker);
}

static t_color3	get_checker_val(
				const t_texture *self, const t_hit_record *h_rec)
{
	const t_texture_checker	*checker = (t_texture_checker *)self;
	const double			sines = sin(10 * h_rec->p.x) \
									* sin(10 * h_rec->p.y) \
									* sin(10 * h_rec->p.z);

	if (sines < 0)
		return (checker->odd->get_val(checker->odd, h_rec));
	else
		return (checker->even->get_val(checker->even, h_rec));
}

static void	destroy_checker(t_texture *self)
{
	t_texture_checker	*checker;

	checker = (t_texture_checker *)self;
	checker->even->destroy(checker->even);
	checker->odd->destroy(checker->odd);
	free(self);
}
