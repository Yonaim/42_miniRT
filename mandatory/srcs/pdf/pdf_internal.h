#ifndef PDF_INTERNAL_H
# define PDF_INTERNAL_H

# define __USE_MISC
# define __USE_XOPEN
# include <math.h>
# include <stdlib.h>
# include "libmath.h"
# include "s_pdf.h"
# include "object_arr.h"
# include "typedef.h"

void	init_light_arr_pdf(t_light_arr_pdf *light_pdf, t_object_arr *lights);
void	init_cosine_pdf(t_cosine_pdf *cosine_pdf);
void	update_cosine_pdf(t_cosine_pdf *cosine_pdf, const t_vector3 *normal_vec);
void	update_light_arr_pdf(t_light_arr_pdf *light_pdf, const t_point3 *origin);

#endif