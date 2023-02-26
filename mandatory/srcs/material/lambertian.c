
#include "material_internal.h"

static bool		lambertian_scattered(\
							t_material *self, t_ray *in, \
							t_hit_record *h_rec, t_scatter_record *s_rec);
static t_color3	lambertian_emitted(\
								t_material *self, \
								double u, double v, t_point3 p);
static void		destroy_lambertian(t_material *self);


t_material	*new_lambertian(t_texture *texture)
{
	t_material_lambertian	*lambertian;

	lambertian = malloc(sizeof(t_material_lambertian));
	if (!lambertian)
		return (NULL);
	lambertian->albedo = texture;
	lambertian->scattered = lambertian_scattered;
	lambertian->emitted = lambertian_emitted;
	lambertian->destroy = destroy_lambertian;
	return ((t_material *)lambertian);
}

static bool	lambertian_scattered(\
							t_material *self, t_ray *in, \
							t_hit_record *h_rec, t_scatter_record *s_rec)
{
	const t_material_lambertian	*lambertian = (t_material_lambertian *)self;
	t_texture_solid				*solid;

	(void)in;
	s_rec->scattered = diffused_ray(h_rec);
	solid = (t_texture_solid *)lambertian->albedo;
	s_rec->attenuation = solid->get_val(\
						(t_texture *)solid, h_rec->u, h_rec->v, h_rec->p);
	return (true);
}

static t_color3	lambertian_emitted(\
								t_material *self, \
								double u, double v, t_point3 p)
{
	(void)self;
	(void)u;
	(void)v;
	(void)p;
	return (color3(0, 0, 0));
}

static void		destroy_lambertian(t_material *self)
{
	t_material_lambertian	*lambertian;

	lambertian = (t_material_lambertian *)self;
	lambertian->albedo->destroy(lambertian->albedo);
	free(lambertian);
}
