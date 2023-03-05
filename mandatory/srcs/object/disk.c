#include "object_internal.h"

static void	destroy_disk(t_object *object);
static int	get_disk_type(void);
static bool	hit_disk(
				t_object *self, t_ray *ray, t_hit_record *h_rec, double t_max);

t_object	*new_disk(t_info_object_disk *dk_info)
{
	t_object_disk	*new;

	new = malloc(sizeof(t_object_disk));
	if (new == NULL)
		return (NULL);
	new->hit = hit_disk;
	new->destroy = destroy_disk;
	new->get_type = get_disk_type;
	new->material = new_material(&dk_info->material);
	if (new->material == NULL)
		return (NULL);
	new->center = dk_info->center;
	new->radius = dk_info->radius;
	new->normal = dk_info->normal;
	return ((t_object *)new);
}

static void	destroy_disk(t_object *object)
{
	t_object_disk	*dk;

	dk = (t_object_disk *)object;
	dk->material->destroy(dk->material);
	free(dk);
}

static int	get_disk_type(void)
{
	return (OBJECT_DISK);
}

/*
	<Line-Disk intersection>

	A disk can be thought of as a limited-area plane, 
	given its center and radius.
	So intersection check the same as the plane, 
	but further check the distance between the center and the radius.

	Disk: (P - C) * n = 0 (|P - C| <= r)
		(P: point on the disk)
		(C: center of the disk)
		(n: normal vector of a disk)
		(r: radius of the disk)

	Line: P(t) = o + t * dir
		(P(t): point this line points to)
		(O: origin of line)
		(dir: direction vector of line)
		(t: scalar value of the direction vector)

	Combining these two equations yields an equation for t.
	The solution of this equation is the case they intersect.

	-> t = (C - O) * n / (n * dir) (|P - C| <= r)
	(If there are countless solutions, it means that a line is contained 
	in the disk.)
	(If a given ray is contained in a disk, it is considered not hit)
*/

static bool	hit_disk(
			t_object *self, t_ray *ray, t_hit_record *h_rec, double t_max)
{
	const t_object_disk		*dk = (t_object_disk *)self;
	double					t;
	t_point3				p;

	if (fabs(v3_dot(dk->normal, ray->dir)) < EPSILON)
		return (false);
	t = v3_dot(v3_sub(dk->center, ray->origin), dk->normal)
		/ v3_dot(dk->normal, ray->dir);
	if (t < T_MINIMUM || t > t_max)
		return (false);
	p = ray_at(ray, t);
	if (len_v3(v3_sub(dk->center, p)) > dk->radius)
		return (false);
	h_rec->t = t;
	h_rec->p = p;
	h_rec->material = dk->material;
	set_face_normal(h_rec, ray, dk->normal);
	return (true);
}
