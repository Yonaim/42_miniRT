
#include "material_internal.h"

static bool		metal_scattered(
					t_material *self, t_ray *in,
					t_hit_record *h_rec, t_scatter_record *s_rec);
static t_color3	metal_emitted(
					t_material *self, double u, double v, t_point3 p);
static void		destroy_metal(t_material *self);
static int		get_metal_type(void);

t_material	*new_metal(t_color3 rgb, double fuzz)
{
	t_material_metal	*metal;

	metal = malloc(sizeof(t_material_metal));
	if (!metal)
		return (NULL);
	metal->destroy = destroy_metal;
	metal->emitted = metal_emitted;
	metal->scattered = metal_scattered;
	metal->get_type = get_metal_type;
	metal->fuzz = fuzz;
	metal->albedo = v3_div(rgb, 256);
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

static t_color3	metal_emitted(
				t_material *self, double u, double v, t_point3 p)
{
	(void)self;
	(void)u;
	(void)v;
	(void)p;
	return (color3(0, 0, 0));
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