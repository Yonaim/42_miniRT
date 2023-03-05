#include "object_internal.h"

static void		destroy_box(t_object *self);
static int		get_box_type(void);
static bool		hit_box(
					t_object *self, t_ray *ray,
					t_hit_record *h_rec, double t_max);
static int		add_box_faces(t_object_box *box, t_info_object_box *bo_info);

t_object	*new_box(t_info_object_box *bo_info)
{
	t_object_box	*new;

	new = malloc(sizeof(t_object_box));
	if (new == NULL)
		return (NULL);
	new->hit = hit_box;
	new->destroy = destroy_box;
	new->get_type = get_box_type;
	if (init_object_arr(&new->faces, 6) == FAILURE)
		return (NULL);
	if (add_box_faces(new, bo_info) == FAILURE)
		return (NULL);
	return ((t_object *)new);
}

static bool	hit_box(
			t_object *self, t_ray *ray, t_hit_record *h_rec, double t_max)
{
	t_object_box	*box;

	box = (t_object_box *)self;
	return (hit_object_arr(&box->faces, ray, h_rec, t_max));
}

static int	add_box_faces(t_object_box *box, t_info_object_box *bo_info)
{
	t_object	*objects[6];

	objects[0] = new_xy_rectangle(&bo_info->xy_rectangle[0]);
	objects[1] = new_xy_rectangle(&bo_info->xy_rectangle[1]);
	objects[2] = new_xz_rectangle(&bo_info->xz_rectangle[0]);
	objects[3] = new_xz_rectangle(&bo_info->xz_rectangle[1]);
	objects[4] = new_yz_rectangle(&bo_info->yz_rectangle[0]);
	objects[5] = new_yz_rectangle(&bo_info->yz_rectangle[1]);
	if (add_n_objects(&box->faces, objects, 6) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static void	destroy_box(t_object *self)
{
	t_object_box	*box;

	box = (t_object_box *)self;
	clear_object_arr(&box->faces);
	free(box);
}

static int	get_box_type(void)
{
	return (OBJECT_BOX);
}
