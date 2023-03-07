#include "ray_internal.h"

void	calculate_diffused_ray(t_hit_record *h_rec, t_scatter_record *s_rec)
{
	t_vector3	diffused_vec;

	diffused_vec = s_rec->mixture_pdf->generate((t_pdf *)s_rec->mixture_pdf);
// error_log("%lf, %lf, %lf", diffused_vec.x, diffused_vec.y, diffused_vec.z);	
	s_rec->ray = ray(h_rec->p, diffused_vec);
}
