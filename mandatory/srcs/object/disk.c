#include "object_internal.h"

static void	destroy_disk(t_object *object);
static int	get_disk_type(void);
static bool	hit_disk(
				t_object *self, t_ray *ray, t_hit_record *h_rec, double t_max);
static bool	is_disk_light(t_object *object);

t_object	*new_disk(t_info_object_disk *di_info)
{
	t_object_disk	*new;

	new = malloc(sizeof(t_object_disk));
	if (new == NULL)
		return (NULL);
	new->hit = hit_disk;
	new->destroy = destroy_disk;
	new->get_type = get_disk_type;
	new->is_light = is_disk_light;
	new->material = new_material(&di_info->material, &di_info->texture);
	if (new->material == NULL)
		return (NULL);
	new->center = di_info->center;
	new->radius = di_info->radius;
	new->normal = di_info->normal;
	return ((t_object *)new);
}

static void	destroy_disk(t_object *object)
{
	t_object_disk	*di;

	di = (t_object_disk *)object;
	di->material->destroy(di->material);
	free(di);
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
	const t_object_disk		*di = (t_object_disk *)self;
	double					t;
	t_point3				p;

	if (fabs(v3_dot(di->normal, ray->dir)) < EPSILON)
		return (false);
	t = v3_dot(v3_sub(di->center, ray->origin), di->normal)
		/ v3_dot(di->normal, ray->dir);
	if (t < T_MINIMUM || t > t_max)
		return (false);
	p = ray_at(ray, t);
	if (len_v3(v3_sub(di->center, p)) > di->radius)
		return (false);
	h_rec->t = t;
	h_rec->p = p;
	h_rec->material = di->material;
	set_face_normal(h_rec, ray, di->normal);
	return (true);
}

static bool	is_disk_light(t_object *object)
{
	const t_object_disk	*di = (t_object_disk *)object;

	if (di->material->get_type() == MATERIAL_EMMISIVE)
		return (true);
	return (false);
}
