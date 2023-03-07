#ifndef PDF_H
# define PDF_H

# include "typedef.h"
# include "s_pdf.h"

void	init_mixture_pdf(t_mixture_pdf *m_pdf, t_object_arr *lights);
void	update_mixture_pdf(
		t_mixture_pdf *m_pdf,
		t_point3 *origin, const t_vector3 *normal_vec);

#endif