#include "pdf_internal.h"

static double		calculate_mixture_sampling_pdf(
						const t_pdf *self, const t_vector3 *dir);
static t_vector3	generate_mixture_random_vector(const t_pdf *self);

void	init_mixture_pdf(t_mixture_pdf *m_pdf, t_object_arr *lights)
{
	m_pdf->get_val = calculate_mixture_sampling_pdf;
	m_pdf->generate = generate_mixture_random_vector;
	init_cosine_pdf(&m_pdf->cosine_pdf);
	init_light_arr_pdf(&m_pdf->light_arr_pdf, lights);
}

void	update_mixture_pdf(
		t_mixture_pdf *m_pdf,
		t_point3 *origin, const t_vector3 *normal_vec)
{
	m_pdf->origin = *origin;
	m_pdf->light_arr_pdf.origin = *origin;
	build_onb_from_w(&m_pdf->cosine_pdf.onb, normal_vec);
}

// t_pdf	*new_mixture_pdf(void)
// {
// 	t_mixture_pdf	*new;

// 	new = malloc(sizeof(t_mixture_pdf));
// 	if (new == NULL)
// 		return (NULL);
// 	new->get_val = calculate_mixture_sampling_pdf;
// 	new->generate = generate_mixture_random_vector;
// 	return (new);
// }

static double	calculate_mixture_sampling_pdf(
				const t_pdf *self, const t_vector3 *dir)
{
//error_log("%lf %lf %lf", dir->x, dir->y, dir->z);
	const t_mixture_pdf	*mixture_pdf = (t_mixture_pdf *)self;
	const t_pdf			*cosine_pdf = (t_pdf *)&mixture_pdf->cosine_pdf;
	const t_pdf			*light_arr_pdf = (t_pdf *)&mixture_pdf->light_arr_pdf;
	const double		c_pdf_val = cosine_pdf->get_val(cosine_pdf, dir);
	const double		l_pdf_val = light_arr_pdf->get_val(light_arr_pdf, dir);

	// sum = 0.5 * cosine_pdf->get_val(cosine_pdf, dir) \
	// 		+ 0.5 * light_arr_pdf->get_val(light_arr_pdf, dir);
//error_log("0.5 * %lf + 0.5 * %lf = %lf", c_pdf_val, l_pdf_val, sum);
	return (0.5 * c_pdf_val + 0.5 * l_pdf_val);
}

static t_vector3	generate_mixture_random_vector(const t_pdf *self)
{
	const t_mixture_pdf	*m_pdf = (t_mixture_pdf *)self;
	const double		random_number = random_double();

	if (random_number < 0.5)
		return (m_pdf->cosine_pdf.generate((t_pdf *)(&m_pdf->cosine_pdf)));
	else
		return (m_pdf->light_arr_pdf.generate(\
				(t_pdf *)(&m_pdf->light_arr_pdf)));
}
