#include "object_internal.h"

static void	destroy_cylinder(t_object *object);
static int	get_cylinder_type(void);
static bool	hit_cylinder(
				t_object *self, t_ray *ray, t_hit_record *h_rec, double t_max);
static bool	is_cylinder_light(t_object *object);

t_object	*new_cylinder(t_info_object_cylinder *cy_info)
{
	t_object_cylinder	*new;

	new = malloc(sizeof(t_object_cylinder));
	if (new == NULL)
		return (NULL);
	new->hit = hit_cylinder;
	new->destroy = destroy_cylinder;
	new->get_type = get_cylinder_type;
	new->is_light = is_cylinder_light;
	if (init_object_arr(&new->faces, 3) == FAILURE)
		return (NULL);
	if (add_object(&new->faces, new_tube(&cy_info->tube)) == FAILURE
		|| add_object(&new->faces, new_disk(&cy_info->disk[0])) == FAILURE
		|| add_object(&new->faces, new_disk(&cy_info->disk[1])) == FAILURE)
		return (NULL);
	return ((t_object *)new);
}

static void	destroy_cylinder(t_object *object)
{
	t_object_cylinder	*cy;

	cy = (t_object_cylinder *)object;
	clear_object_arr(&cy->faces);
	free(cy);
}

static int	get_cylinder_type(void)
{
	return (OBJECT_CYLINDER);
}

/*
	<Line-Cylinder intersection>

	The cylinder consists of three faces, one tube and two disks.
	Check the intersection of these faces and line.
*/
static bool	hit_cylinder(
			t_object *self, t_ray *ray, t_hit_record *h_rec, double t_max)
{
	t_object_cylinder	*cy;

	cy = (t_object_cylinder *)self;
	return (hit_object_arr(&cy->faces, ray, h_rec, t_max));
}

static bool	is_cylinder_light(t_object *object)
{
	const t_object_cylinder	*cy = (t_object_cylinder *)object;
	t_object				*face;

	face = (t_object *)(cy->faces.data[0]);
	if (face->is_light(face) == true)
		return (true);
	return (false);
}
