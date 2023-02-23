#include "shading_internal.h"

static bool	hit_world(t_world *world, t_ray *ray, t_hit_record *final_rec)
{
	bool			is_hit;
	double			closest_t;
	t_hit_record	cur_rec;
	t_object		*cur_obj;
	t_list			*cur_node;

	is_hit = false;
	closest_t = T_INFINITY;
	cur_node = world->object_list;
	while (cur_node)
	{
		cur_obj = (t_object *)&world->object_list->content;
		if (cur_obj->hit(cur_obj, ray, &cur_rec, closest_t) == true)
		{
			is_hit = true;
			*final_rec = cur_rec;
			closest_t = cur_rec.t;
		}
		cur_node = cur_node->next;
	}
	return (is_hit);
}

t_color3	traced_color(t_ray *ray, t_world *world, int depth)
{
	t_hit_record		h_rec;
	t_scatter_record	s_rec;

	if (depth <= 0)
		return (color(0, 0, 0));
	if (hit_world(world, ray, &h_rec) == true)
	{
		if (h_rec.material->scatter(h_rec.material, ray, &h_rec, &s_rec) \
																	== false)
			return (color(0, 0, 0));
		return (v3_comp_wise(traced_color(\
										&s_rec.scattered, world, depth - 1), \
										s_rec.attenuation));
	}
	return (world->background_color);
}
