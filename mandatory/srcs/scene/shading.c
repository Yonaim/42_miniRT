# include "scene_internal.h"

static bool	hit_world(
			t_object_arr *objects, t_ray *in_ray,
			t_hit_record *h_rec, int depth)
{
	if (depth == 0)
		return (hit_object_arr_except_point_light(\
										objects, in_ray, h_rec, T_INFINITY));
	else
		return (hit_object_arr(objects, in_ray, h_rec, T_INFINITY));
	return (false);
}

t_color3	traced_color(t_ray *ray, t_world *world, int depth)
{
	t_hit_record		h_rec;
	t_scatter_record	s_rec;
	t_material			*material;
	t_color3			color;

// error_log("%d", depth);
	if (depth >= MAX_DEPTH)
		return (color3(0, 0, 0));
	if (hit_world(&world->objects, ray, &h_rec, depth) == false)
		return (world->background_color);
	material = h_rec.material;
	if (material->emit(material, &h_rec, &color) == true)
		return (color);
	s_rec.mixture_pdf = &world->mixture_pdf;
	material->scatter(material, ray, &h_rec, &s_rec);
	color = v3_mul(s_rec.albedo, s_rec.s_pdf_val);
	color = v3_comp_wise(color, traced_color(&s_rec.ray, world, depth + 1));
	color = v3_div(color, s_rec.pdf_val);
	return (color);
}
