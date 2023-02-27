#include "shading_internal.h"

t_color3	traced_color(t_ray *in_ray, t_world *world, int depth)
{
	t_hit_record		h_rec;
	t_scatter_record	s_rec;
	t_material			*material;
	t_color3			emitted;
	t_color3			summed;

	if (depth <= 0)
		return (color3(0, 0, 0));
	if (hit_objects(&world->objects, in_ray, &h_rec, T_INFINITY) == false)
		return (world->background_color);
	material = h_rec.material;
	emitted = material->emitted(material, h_rec.u, h_rec.v, h_rec.p);
	if (material->scattered(material, in_ray, &h_rec, &s_rec) == false)
		return (emitted);
	/* summed = v3_mul(v3_comp_wise(\
	// 					traced_color(&s_rec.scattered, world, depth - 1), \
	// 					s_rec.attenuation), \
	// 				material->s_pdf(material, in_ray, &h_rec, &s_rec) \
	// 					/ s_rec.pdf_val);
	*/
	summed = v3_comp_wise(\
						traced_color(&s_rec.scattered, world, depth - 1), \
						s_rec.attenuation);
	return (v3_add(summed, emitted));
}
