
#include "material_internal.h"

static bool	scatter_metal(\
						t_material *self, t_ray *in, \
						t_hit_record *h_rec, t_scatter_record *s_rec)
{
	const t_material_metal	*metal = (t_material_metal *)self;

	s_rec->scattered = reflected_ray(in->dir, h_rec, metal->fuzz);
	s_rec->attenuation = metal->albedo;
	if (v3_dot_product(s_rec->scattered.dir, h_rec->normal) > 0)
		return (true);
	else
		return (false);
}

t_material_metal	material_metal(t_color albedo, double fuzz)
{
	t_material_metal	metal;

	metal.albedo = albedo;
	metal.fuzz = fuzz;
	metal.scatter = scatter_metal;
	return (metal);
}
