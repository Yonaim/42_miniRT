#ifndef S_SCATTER_RECORD_H
# define S_SCATTER_RECORD_H

# include <stdbool.h>
# include "typedef.h"
# include "s_ray.h"
// pdf = probability density function

struct s_scatter_record
{
	bool		is_specular;
	t_ray		scattered;
	t_color3	attenuation;
	t_ray		specular_ray;
	double		pdf_val;
};

#endif