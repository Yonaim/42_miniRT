#include "object_internal.h"
#include "object_arr.h"
#include "object.h"

static bool		hit_box(\
					t_object *self, \
					t_ray *ray, t_hit_record *h_rec, double t_max);
static void		get_box_uv(t_hit_record *record);
static t_error	add_box_sides(t_object_box *box, t_material *material);
static void		destroy_box(t_object *self);

t_object	*new_box(t_point3 p_min, t_point3 p_max, t_material *material)
{
	t_object_box	*new;

	new = malloc(sizeof(t_object_box));
	if (!new)
		return (NULL);
	new->p_min = p_min;
	new->p_max = p_max;
	new->hit = hit_box;
	new->material = material;
	if (init_object_arr(&new->sides, 6) == ERROR)
		return (ERROR);
	if (add_box_sides(new, material) == ERROR)
		return (ERROR);
	new->destroy = destroy_box;
	return ((t_object *)new);
}

static bool	hit_box(\
			t_object *self, t_ray *ray, t_hit_record *h_rec, double t_max)
{
	const t_object_box	*cy = (t_object_box *)self;

	(void)cy;
	(void)ray;
	(void)h_rec;
	(void)t_max;
	get_box_uv(h_rec);
	return (true);
}

static void	get_box_uv(t_hit_record *record)
{
	(void)record;
}

static t_error	add_box_sides(t_object_box *box, t_material *material)
{
	t_object		*object[6];
	const double	intvl[3][2] = {{box->p_min.x, box->p_min.x}, \
										{box->p_min.y, box->p_min.y}, \
										{box->p_min.z, box->p_min.z}};
	const double	const_k[6] = {box->p_max.z, box->p_min.z,\
									box->p_max.y, box->p_min.y, \
									box->p_max.x, box->p_min.x};
	int				i;


	object[0] = new_xy_rectangle(intvl[0], intvl[1], const_k[0], material);
	object[1] = new_xy_rectangle(intvl[0], intvl[1], const_k[1], material);
	object[2] = new_yz_rectangle(intvl[0], intvl[2], const_k[2], material);
	object[3] = new_yz_rectangle(intvl[0], intvl[2], const_k[3], material);
	object[4] = new_xz_rectangle(intvl[1], intvl[2], const_k[4], material);
	object[5] = new_xz_rectangle(intvl[1], intvl[2], const_k[5], material);
	i = 0;
	while (i < 6)
	{
		if (object[i] == NULL)
			return (ERROR);
		if (add_object(&box->sides, object[i]) == ERROR)
			return (ERROR);
		i++;
	}
	return (ERROR_NONE);
}

static void	destroy_box(t_object *self)
{
	t_object_box	*box;
	int				i;

	box = (t_object_box *)self;
	i = 0;
	while (i < 6)
	{
		free(box->sides.arr[i]);
		i++;
	}
	box->material->destroy(box->material);
	free(box);
}
