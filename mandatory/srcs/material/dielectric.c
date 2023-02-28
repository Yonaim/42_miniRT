
#include "material_internal.h"

static bool		dielectric_scattered(
					t_material *self, t_ray *in,
					t_hit_record *h_rec, t_scatter_record *s_rec);
static t_color3	dielectric_emitted(t_material *self, t_hit_record *h_rec);
static void		destroy_dielectric(t_material *self);

t_material	*new_dielectric(double refractive_idx)
{
	t_material_dielectric	*dielectric;

	dielectric = malloc(sizeof(t_material_dielectric));
	if (!dielectric)
		return (NULL);
	dielectric->refractive_idx = refractive_idx;
	dielectric->scattered = dielectric_scattered;
	dielectric->emitted = dielectric_emitted;
	dielectric->destroy = destroy_dielectric;
	return ((t_material *)dielectric);
}

static bool	dielectric_scattered(
			t_material *self, t_ray *in,
			t_hit_record *h_rec, t_scatter_record *s_rec)
{
	const t_material_dielectric	*dielectric = (t_material_dielectric *)self;
	double						refractive_idx_ratio;

	s_rec->albedo = color3(1, 1, 1);
	if (h_rec->opposed == true)
		refractive_idx_ratio = 1 / dielectric->refractive_idx;
	else
		refractive_idx_ratio = dielectric->refractive_idx;
	s_rec->scattered = refracted_ray(in->dir, h_rec, refractive_idx_ratio);
	return (true);
}

static t_color3	dielectric_emitted(t_material *self, t_hit_record *h_rec)
{
	(void)self;
	(void)h_rec;
	return (color3(0, 0, 0));
}

static void	destroy_dielectric(t_material *self)
{
	t_material_dielectric	*dielectric;

	dielectric = (t_material_dielectric *)self;
	free(dielectric);
}
