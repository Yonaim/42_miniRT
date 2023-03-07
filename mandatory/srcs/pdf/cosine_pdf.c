#include "pdf_internal.h"

static double		calculate_cosine_sampling_pdf(
						const t_pdf *self, const t_vector3 *dir);
static t_vector3	generate_cosine_random_vector(
						const t_pdf *self);

void	init_cosine_pdf(t_cosine_pdf *cosine_pdf)
{
	cosine_pdf->get_val = calculate_cosine_sampling_pdf;
	cosine_pdf->generate = generate_cosine_random_vector;
}

void	update_cosine_pdf(t_cosine_pdf *cosine_pdf, const t_vector3 *normal_vec)
{
	build_onb_from_w(&cosine_pdf->onb, normal_vec);
}

static double	calculate_cosine_sampling_pdf(
				const t_pdf *self, const t_vector3 *dir)
{
	const t_cosine_pdf	*cosine_pdf = (t_cosine_pdf *)self;
	const double		cosine = v3_dot(v3_normalize(*dir), cosine_pdf->onb.w);

	if (cosine <= 0)
		return (0);
	else
		return (cosine / M_PI);
}

// polar angle : 편각
// azimuthal angle : 방위각
static void	generate_random_cosine_direction(t_vector3 *random_dir)
{
	const double	rand_num1 = random_double();
	const double	rand_num2 = random_double();
	const double	azimuthal_angle = 2 * M_PI * rand_num1;
	const double	cos_polar_angle = sqrt(1 - rand_num2);
	const double	sin_polar_angle = sqrt(rand_num2);

	(*random_dir).x = cos(azimuthal_angle) * sin_polar_angle;
	(*random_dir).y = sin(azimuthal_angle) * sin_polar_angle;
	(*random_dir).z = cos_polar_angle;
}

static t_vector3	generate_cosine_random_vector(const t_pdf *self)
{
	const t_cosine_pdf	*cosine_pdf = (t_cosine_pdf *)self;
	t_vector3			random_dir;

	generate_random_cosine_direction(&random_dir);
	transform_to_onb_in_place(&cosine_pdf->onb, &random_dir);
// error_log("generated cosine random vector!");
	return (random_dir);
}
