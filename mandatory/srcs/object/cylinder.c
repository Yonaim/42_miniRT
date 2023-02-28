# include "object_internal.h"

static void	destroy_cylinder(t_object *object);
static int	get_cylinder_type(void);
static bool	hit_cylinder(t_object *self, t_ray *ray, \
						t_hit_record *h_rec, double t_max);

t_object	*new_cylinder(t_object_tube *tube, t_object_disk *disk[2])
{
	t_object_cylinder	*new;

	(void)tube;
	(void)disk;
	new = malloc(sizeof(t_object_cylinder));
	if (!new)
		return (NULL);
	ft_memset(new, 0, sizeof(t_object_cylinder));
	// new->faces
	return ((t_object *)new);
}

static void	destroy_cylinder(t_object *object)
{
	t_object_cylinder	*cy;

	cy = (t_object_cylinder *)object;
	cy->material->destroy(cy->material);
	flush_object_arr(&cy->faces);
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
static bool	hit_cylinder(t_object *self, t_ray *ray, \
						t_hit_record *h_rec, double t_max)
{
	t_object_cylinder	*cy;
	
	cy = (t_object_cylinder *)self;
	return (hit_object_arr(&cy->faces, ray, h_rec, t_max));
}
