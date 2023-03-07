
#include "material_internal.h"

static void		destroy_lambertian(t_material *self);
static bool		lambertian_emit(
					t_material *self, t_hit_record *h_rec, t_color3 *emission);
static bool		lambertian_scatter(
					t_material *self, t_ray *in,
					t_hit_record *h_rec, t_scatter_record *s_rec);
static int		get_lambertian_type(void);

t_material	*new_lambertian(t_texture *texture)
{
	t_material_lambertian	*lambertian;

	lambertian = malloc(sizeof(t_material_lambertian));
	if (!lambertian)
		return (NULL);
	lambertian->scatter = lambertian_scatter;
	lambertian->emit = lambertian_emit;
	lambertian->destroy = destroy_lambertian;
	lambertian->get_type = get_lambertian_type;
	lambertian->albedo = texture;
	return ((t_material *)lambertian);
}

static void	destroy_lambertian(t_material *self)
{
	t_material_lambertian	*lambertian;

	lambertian = (t_material_lambertian *)self;
	lambertian->albedo->destroy(lambertian->albedo);
	free(lambertian);
}

static bool	lambertian_emit(
			t_material *self, t_hit_record *h_rec, t_color3 *emission)
{
	(void)self;
	(void)h_rec;
	*emission = color3(0, 0, 0);
	return (false);
}

static bool	lambertian_scatter(
			t_material *self, t_ray *in_ray,
			t_hit_record *h_rec, t_scatter_record *s_rec)
{
	const t_material_lambertian	*lambertian = (t_material_lambertian *)self;
	const t_texture_solid		*solid = (t_texture_solid *)lambertian->albedo;

//error_log("%p", s_rec->mixture_pdf);
//error_log("%p", &s_rec->mixture_pdf->light_arr_pdf);
//error_log("%p", s_rec->mixture_pdf->light_arr_pdf.lights);
	(void)in_ray;
	update_mixture_pdf(s_rec->mixture_pdf, &h_rec->p, &h_rec->normal);
	calculate_diffused_ray(h_rec, s_rec);
	s_rec->albedo = solid->get_val((t_texture *)solid, h_rec);
	s_rec->pdf_val = s_rec->mixture_pdf->get_val(\
					(t_pdf *)s_rec->mixture_pdf, &s_rec->ray.dir);
	s_rec->s_pdf_val = v3_dot(h_rec->normal, s_rec->ray.dir) / M_PI;
// error_log("%lf", s_rec->pdf_val);
// error_log("%lf", s_rec->s_pdf_val);
	if (s_rec->s_pdf_val < 0)
		s_rec->s_pdf_val = 0;
	return (true);
}

static int	get_lambertian_type(void)
{
	return (MATERIAL_LAMBERTIAN);
}
