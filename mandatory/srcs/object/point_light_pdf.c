#include "object_internal.h"

double	calculate_point_light_sampling_pdf(
		t_object *self, const t_vector3 *origin, const t_vector3 *dir)
{
	t_object	*sp;

	sp = (t_object *)((t_object_point_light*)self)->sphere;
	return (sp->pdf_value(sp, origin, dir));
	// const t_object_point_light	*ptl = (t_object_point_light *)self;
	// const t_ray					ptl_ray = ray(*origin, *dir);
	// t_hit_record				h_rec;

	// if (ptl->hit(self, (t_ray *)&ptl_ray, &h_rec, T_INFINITY) == false)
	// 	return (0);
	// return (0.001);
}

t_vector3	get_random_vector_to_point_light(
			const t_object *self, const t_point3 *origin)
{
	t_object	*sp;

	sp = (t_object *)((t_object_point_light*)self)->sphere;
	return (sp->random(sp, origin));
	// return (v3_sub(((t_object_point_light *)self)->center, *origin));
}
