# include "object_internal.h"

t_object	*new_cylinder(t_object_tube *tube, t_object_disk *disk[2])
{
	t_object_cylinder	*new;

	new = malloc(sizeof(t_object_cylinder));
	if (!new)
		return (NULL);
	ft_memset(new, 0, sizeof(t_object_cylinder));
	// new->faces
	return ((t_object *)new);
}

/*
	<Line-Cylinder intersection>

	The cylinder consists of three faces, one tube and two disks.
	Check the intersection of these faces and line.
*/
bool		hit_cylinder(t_object *self, t_ray *ray, \
						t_hit_record *h_rec, double t_max)
{
	const t_object_cylinder	*cy = (t_object_cylinder *)self;

	return (hit_object_list(cy->object_list, ray, h_rec, t_max));
}
