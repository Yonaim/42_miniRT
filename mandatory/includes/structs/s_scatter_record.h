#ifndef S_SCATTER_RECORD_H
# define S_SCATTER_RECORD_H

# include <stdbool.h>
# include "typedef.h"
# include "s_ray.h"
# include "s_pdf.h"
// pdf = probability density function

struct s_scatter_record
{
	t_ray			ray;
	t_color3		albedo;
	double			pdf_val;
	double			s_pdf_val;
	t_mixture_pdf	*mixture_pdf;
	// t_ray	specular_ray;
};

#endif