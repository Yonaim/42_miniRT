#include "object_internal.h"

static void		destroy_box(t_object *self);
static int		get_box_type(void);
static bool		hit_box(
					t_object *self, t_ray *ray,
					t_hit_record *h_rec, double t_max);
int				add_box_faces(t_object_box *box, t_info_object_box *bo_info);

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
