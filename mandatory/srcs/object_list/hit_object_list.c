#include "object_list_internal.h"

bool	hit_object_list(t_object_list *objects, t_ray *ray, \
						t_hit_record *final_rec, double t_max)
{
	bool			is_hit;
	double			closest_t;
	t_hit_record	cur_rec;
	t_object		*cur_obj;
	t_list			*cur_node;

	is_hit = false;
	closest_t = t_max;
	cur_node = objects->list;
	while (cur_node)
	{
		cur_obj = (t_object *)cur_node->content;
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
