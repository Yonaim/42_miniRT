
#include "material_internal.h"

static void		destroy_dielectric(t_material *self);
static bool		dielectric_emit(
					t_material *self, t_hit_record *h_rec, t_color3 *emission);
static bool		dielectric_scatter(
					t_material *self, t_ray *in,
					t_hit_record *h_rec, t_scatter_record *s_rec);
static int		get_dielectric_type(void);

t_material	*new_dielectric(double refractive_idx)
{
	t_material_dielectric	*dielectric;

	dielectric = malloc(sizeof(t_material_dielectric));
	if (!dielectric)
		return (NULL);
	dielectric->destroy = destroy_dielectric;
	dielectric->emit = dielectric_emit;
	dielectric->scatter = dielectric_scatter;
	dielectric->get_type = get_dielectric_type;
	dielectric->refractive_idx = refractive_idx;
	return ((t_material *)dielectric);
}

static void	destroy_dielectric(t_material *self)
{
	t_material_dielectric	*dielectric;

	dielectric = (t_material_dielectric *)self;
	free(dielectric);
}

static bool	dielectric_emit(
			t_material *self, t_hit_record *h_rec, t_color3 *emission)
{
	(void)self;
	(void)h_rec;
	*emission = color3(0, 0, 0);
	return (false);
}

static bool	dielectric_scatter(
			t_material *self, t_ray *in_ray,
			t_hit_record *h_rec, t_scatter_record *s_rec)
{
	const t_material_dielectric	*dielectric = (t_material_dielectric *)self;
	double						refractive_idx_ratio;

	s_rec->albedo = color3(1, 1, 1);
	if (h_rec->opposed == true)
		refractive_idx_ratio = 1 / dielectric->refractive_idx;
	else
		refractive_idx_ratio = dielectric->refractive_idx;
	s_rec->ray = refracted_ray(in_ray->dir, h_rec, refractive_idx_ratio);
	s_rec->pdf_val = 1;
	s_rec->s_pdf_val = 1;
	return (true);
}

static int	get_dielectric_type(void)
{
	return (MATERIAL_DIELECTRIC);
}
