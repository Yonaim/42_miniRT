
#include "material_internal.h"

static bool		metal_scattered(
					t_material *self, t_ray *in,
					t_hit_record *h_rec, t_scatter_record *s_rec);
static t_color3	metal_emitted(t_material *self, t_hit_record *h_rec);
static void		destroy_metal(t_material *self);

t_material	*new_metal(t_color3 rgb, double fuzz)
{
	t_material_metal	*metal;

	metal = malloc(sizeof(t_material_metal));
	if (!metal)
		return (NULL);
	metal->albedo = v3_div(rgb, 256);
	metal->fuzz = fuzz;
	metal->scattered = metal_scattered;
	metal->emitted = metal_emitted;
	metal->destroy = destroy_metal;
	return ((t_material *)metal);
}

static bool	metal_scattered(
			t_material *self, t_ray *in,
			t_hit_record *h_rec, t_scatter_record *s_rec)
{
	const t_material_metal	*metal = (t_material_metal *)self;

	s_rec->scattered = reflected_ray(in->dir, h_rec, metal->fuzz);
	s_rec->albedo = metal->albedo;
	if (v3_dot(s_rec->scattered.dir, h_rec->normal) > 0)
		return (true);
	else
		return (false);
}

static t_color3	metal_emitted(t_material *self, t_hit_record *h_rec)
{
	(void)self;
	(void)h_rec;
	return (color3(0, 0, 0));
}

static void	destroy_metal(t_material *self)
{
	t_material_metal	*metal;

	metal = (t_material_metal *)self;
	free(metal);
}
