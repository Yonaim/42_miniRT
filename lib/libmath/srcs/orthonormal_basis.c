#include <math.h>
#include "orthonormal_basis.h"

void	build_onb_from_w(t_onb *onb, const t_vector3 *n)
{
	t_vector3	unit;

	onb->w = v3_normalize(*n);
	if (fabs(onb->w.x) > 0.9)
		unit = vector3(0, 1, 0);
	else
		unit = vector3(1, 0, 0);
	onb->v = v3_cross(onb->w, unit);
	onb->u = v3_cross(onb->w, onb->v);
}

void	transform_to_onb(
		const t_onb *onb, const t_vector3 *in_vec, t_vector3 *out_vec)
{
//error_log("%lf %lf %lf", onb->u.x, onb->u.y, onb->u.z);
//error_log("%lf %lf %lf", onb->v.x, onb->v.y, onb->v.z);
//error_log("%lf %lf %lf", onb->w.x, onb->w.y, onb->w.z);

	*out_vec = v3_mul(onb->u, in_vec->x);
	*out_vec = v3_add(*out_vec, v3_mul(onb->v, in_vec->y));
	*out_vec = v3_add(*out_vec, v3_mul(onb->w, in_vec->z));
}

void	transform_to_onb_in_place(const t_onb *onb, t_vector3 *in_vec)
{
	t_vector3	out_vec;

	transform_to_onb(onb, in_vec, &out_vec);
	*in_vec = out_vec;
}
