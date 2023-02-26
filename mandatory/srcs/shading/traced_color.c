#include "shading_internal.h"

static bool	hit_world(t_world *world, t_ray *ray, t_hit_record *final_rec)
{
	bool			is_hit;
	double			closest_t;
	t_hit_record	cur_rec;
	t_object		*cur_obj;
	int				i;

	is_hit = false;
	closest_t = T_INFINITY;
	i = 0;
	while (i < world->objects.cnt)
	{
		cur_obj = (t_object *)world->objects.arr[i];
		if (cur_obj->hit(cur_obj, ray, &cur_rec, closest_t) == true)
		{
			is_hit = true;
			*final_rec = cur_rec;
			closest_t = cur_rec.t;
		}
		i++;
	}
	return (is_hit);
}

t_color3	traced_color(t_ray *in_ray, t_world *world, int depth)
{
	t_hit_record		h_rec;
	t_scatter_record	s_rec;
	t_color3			emitted;
	t_color3			summed;

	if (depth <= 0)
		return (color3(0, 0, 0));
	if (hit_world(world, in_ray, &h_rec) == false)
		return (world->background_color);
	emitted = h_rec.material->emitted(h_rec.material, h_rec.u, h_rec.v, h_rec.p);
	if (h_rec.material->scattered(h_rec.material, in_ray, &h_rec, &s_rec) \
																	== false)
		return (emitted);
	summed = v3_comp_wise(\
						traced_color(&s_rec.scattered, world, depth - 1), \
						s_rec.attenuation);
	return (v3_add(summed, emitted));
}
