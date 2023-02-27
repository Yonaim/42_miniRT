#include "object_arr_internal.h"

static t_error	_grow_object_arr(t_object_arr *objects)
{
	const int	new_cap = objects->cap * 2;
	t_object	**new_objects;

	new_objects = malloc(sizeof(t_object *) * new_cap);
	if (new_objects == NULL)
		return (ERROR);
	ft_memcpy(new_objects, objects->arr, sizeof(t_object *) * objects->cnt);
	objects->cap = new_cap;
	free(objects->arr);
	objects->arr = new_objects;
	return (ERROR_NONE);
}

t_error	add_object(t_object_arr *objects, t_object *object)
{
	if (objects->cnt == objects->cap
		&& _grow_object_arr(objects) == ERROR)
		return (ERROR);
	objects->arr[objects->cnt] = object;
	objects->cnt++;
	return (ERROR_NONE);
}

bool	hit_objects(\
				t_object_arr *objects, \
				t_ray *ray, \
				t_hit_record *final_rec, \
				double t_max)
{
	bool			is_hit;
	double			closest_t;
	t_hit_record	cur_rec;
	t_object		*cur_obj;
	int				i;

	is_hit = false;
	closest_t = t_max;
	i = 0;
	while (i < objects->cnt)
	{
		cur_obj = (t_object *)objects->arr[i];
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
