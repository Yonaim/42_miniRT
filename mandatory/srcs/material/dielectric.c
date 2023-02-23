
#include "material_internal.h"

static bool	scatter_dielectric(\
							t_material *self, t_ray *in, \
							t_hit_record *h_rec, t_scatter_record *s_rec)
{
	const t_material_dielectric	*dielectric = (t_material_dielectric *)self;
	double						refractive_idx_ratio;

	s_rec->attenuation = color(1, 1, 1);
	if (h_rec->opposed == true)
		refractive_idx_ratio = 1 / dielectric->refractive_idx;
	else
		refractive_idx_ratio = dielectric->refractive_idx;
	s_rec->scattered = refracted_ray(in->dir, h_rec, refractive_idx_ratio);
	return (true);
}

t_material_dielectric	material_dielectric(double refractive_idx)
{
	t_material_dielectric	dielectric;

	dielectric.refractive_idx = refractive_idx;
	dielectric.scatter = scatter_dielectric;
	return (dielectric);
}
