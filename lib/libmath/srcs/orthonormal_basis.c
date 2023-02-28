#include <math.h>
#include "orthonormal_basis.h"

t_onb	build_orthonormal_basis_from_w(t_vector3 n)
{
	t_onb		onb;
	t_vector3	unit;

	onb.w = v3_normalize(n);
	if (fabs(onb.w.x) > 0.9)
		unit = vector3(0, 1, 0);
	else
		unit = vector3(1, 0, 0);
	onb.v = v3_normalize(v3_cross(onb.w, unit));
	onb.u = v3_cross(onb.w, onb.v);
	return (onb);
}

t_vector3	onb_local(t_onb onb, t_vector3 v)
{
	t_vector3	local;

	local = v3_mul(onb.u, v.x);
	local = v3_add(local, v3_mul(onb.v, v.y));
	local = v3_add(local, v3_mul(onb.w, v.z));
	return (local);
}
