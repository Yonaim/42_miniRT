# include "object_internal.h"

static void	destroy_cone(t_object *object);
static int	get_cone_type(void);
static bool	hit_cone(t_object *self, t_ray *ray, \
						t_hit_record *h_rec, double t_max);

t_object	*new_cone(t_point3 center, double radius, double height, \
						t_material *material)
{
	;
}

static void	destroy_cone(t_object *object)
{
	t_object_cone	*co;

	co = (t_object_cone *)object;
	co->material->destroy(co->material);
	flush_object_arr(&co->faces);
	free(co);
}

static int	get_cone_type(void)
{
	return (OBJECT_CONE);
}

static bool	hit_cone(t_object *self, t_ray *ray, \
						t_hit_record *h_rec, double t_max)
{
	t_object_cone	*co;
	
	co = (t_object_cone *)self;
	return (hit_object_arr(&co->faces, ray, h_rec, t_max));
}
