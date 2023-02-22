#ifndef S_SCATTER_RECORD_H
# define S_SCATTER_RECORD_H

# include <stdbool.h>
# include "s_ray.h"
# include "s_pdf.h"
# include "color.h"

typedef struct s_scatter_record
{
	bool	is_specular;
	t_ray	scattered;
	t_color	attenuation;
	// probability density function
	t_ray	specular_ray;
	t_pdf	*pdf;
}	t_scatter_record;

#endif