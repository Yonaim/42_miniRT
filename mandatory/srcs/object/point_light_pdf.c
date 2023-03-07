#include "object_internal.h"

double calculate_point_light_sampling_pdf(
		t_object *self, const t_vector3 *origin, const t_vector3 *dir)
{
	t_object	*sp;

//error_log();
	sp = (t_object *)((t_object_point_light*)self)->sphere;
	return (sp->pdf_value(sp, origin, dir));
}

t_vector3	get_random_vector_to_point_light(
			const t_object *self, const t_point3 *origin)
{
	t_object	*sp;

//error_log();
	sp = (t_object *)((t_object_point_light*)self)->sphere;
	return (sp->random(sp, origin));
}