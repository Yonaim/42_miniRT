#include "libmath.h"
#include "s_hit_record.h"
#include "s_ray.h"
#include "typedef.h"

void	set_face_normal(\
		t_hit_record *h_rec, t_ray *in_ray, t_vector3 outward_normal)
{
	if (v3_dot(in_ray->dir, outward_normal) < 0)
	{
		h_rec->opposed = true;
		h_rec->normal = outward_normal;
	}
	else
	{
		h_rec->opposed = false;
		h_rec->normal = v3_mul(outward_normal, -1);
	}
}
