
#include "material_internal.h"

static void		destroy_metal(t_material *self);
static bool		metal_emit(
					t_material *self, t_hit_record *h_rec, t_color3 *emission);
static bool		metal_scatter(
					t_material *self, t_ray *in,
					t_hit_record *h_rec, t_scatter_record *s_rec);
static int		get_metal_type(void);

t_material	*new_metal(t_color3 rgb, double fuzz)
{
	t_material_metal	*metal;

	metal = malloc(sizeof(t_material_metal));
	if (!metal)
		return (NULL);
	metal->destroy = destroy_metal;
	metal->emit = metal_emit;
	metal->scatter = metal_scatter;
	metal->get_type = get_metal_type;
	metal->fuzz = fuzz;
	metal->albedo = v3_div(rgb, 256);
	return ((t_material *)metal);
}

static bool	metal_scatter(
			t_material *self, t_ray *in,
			t_hit_record *h_rec, t_scatter_record *s_rec)
{
	const t_material_metal	*metal = (t_material_metal *)self;

	s_rec->ray = reflected_ray(in->dir, h_rec, metal->fuzz);
	s_rec->albedo = metal->albedo;
	s_rec->s_pdf_val = 1;
	s_rec->pdf_val = 1;
	if (v3_dot(s_rec->ray.dir, h_rec->normal) > 0)
		return (true);
	else
		return (false);
}

static bool	metal_emit(
			t_material *self, t_hit_record *h_rec, t_color3 *emission)
{
	(void)self;
	(void)h_rec;
	*emission = color3(0, 0, 0);
	return (false);
}

static void	destroy_metal(t_material *self)
{
	t_material_metal	*metal;

	metal = (t_material_metal *)self;
	free(metal);
}

static int	get_metal_type(void)
{
	return (MATERIAL_METAL);
}