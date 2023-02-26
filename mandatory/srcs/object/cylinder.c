# include "object_internal.h"

static bool	hit_cylinder(\
				t_object *self, t_ray *ray, t_hit_record *h_rec, double t_max);
static void	get_cylinder_uv(t_hit_record *record);
static void	destroy_cylinder(t_object *self);

t_object	*new_cylinder(\
					t_point3 pos, t_vector3 orient, \
					double radius, double height, t_material *material)
{
	t_object_cylinder	*new;

	new = malloc(sizeof(t_object_cylinder));
	if (!new)
		return (NULL);
	ft_memset(new, 0, sizeof(t_object_cylinder));
	new->center = pos;
	new->orient = orient;
	new->radius = radius;
	new->height = height;
	new->hit = hit_cylinder;
	new->destroy = destroy_cylinder;
	new->material = material;
	return ((t_object *)new);
}

static bool	hit_cylinder(\
			t_object *self, t_ray *ray, t_hit_record *h_rec, double t_max)
{
	const t_object_cylinder	*cy = (t_object_cylinder *)self;

	(void)cy;
	(void)ray;
	(void)h_rec;
	(void)t_max;
	get_cylinder_uv(h_rec);
	return (true);
}

static void	get_cylinder_uv(t_hit_record *record)
{
	(void)record;
}

static void	destroy_cylinder(t_object *self)
{
	t_object_cylinder	*cylinder;

	cylinder = (t_object_cylinder *)self;
	free(cylinder);
}