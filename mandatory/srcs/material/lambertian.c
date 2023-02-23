
#include "material_internal.h"

static bool	scatter_lambertian(\
						t_material *self, t_ray *in, \
						t_hit_record *h_rec, t_scatter_record *s_rec)
{
	const t_material_lambertian	*lambertian = (t_material_lambertian *)self;

	(void)in;
	s_rec->scattered = diffused_ray(h_rec);
	s_rec->attenuation = lambertian->albedo;
	return (true);
}

t_material_lambertian	material_lambertian(t_color3 albedo)
{
	t_material_lambertian	lambertian;

	lambertian.albedo = albedo;
	lambertian.scatter = scatter_lambertian;
	return (lambertian);
}
