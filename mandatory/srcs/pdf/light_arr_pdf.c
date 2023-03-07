#include "pdf_internal.h"

static double		get_light_arr_pdf_value(const t_pdf *self, const t_vector3 *dir);
static t_vector3	generate_light_random_vector(const t_pdf *self);

void	init_light_arr_pdf(t_light_arr_pdf *l_pdf, t_object_arr *lights)
{
	l_pdf->get_val = get_light_arr_pdf_value;
	l_pdf->generate = generate_light_random_vector;
	l_pdf->lights = lights;
	if (lights != NULL && lights->cnt != 0)
		l_pdf->weight = 1 / (double)lights->cnt;
	else
		l_pdf->weight = 1;
//error_log("%lf", l_pdf->weight);
//error_log("%p", l_pdf->lights);
//error_log("%d", l_pdf->lights->cnt);

}

void	update_light_arr_pdf(t_light_arr_pdf *l_pdf, const t_point3 *origin)
{
	l_pdf->origin = *origin;
}

static double	get_light_arr_pdf_value(const t_pdf *self, const t_vector3 *dir)
{
	const t_light_arr_pdf	*l_pdf = (t_light_arr_pdf *)self;
	int						i;
	double					sum;
	t_object				*light;

	i = 0;
	sum = 0;
//error_log("%d", l_pdf->lights->cnt);
	while (i < l_pdf->lights->cnt)
	{
		// light = (t_object *)(l_pdf->lights->data[i]);
		light = get_object(l_pdf->lights, i);
		sum += l_pdf->weight * light->pdf_value(light, &l_pdf->origin, dir);
		i++;
	}
	return (sum);
}

static t_vector3	generate_light_random_vector(const t_pdf *self)
{
	const t_light_arr_pdf	*l_pdf = (t_light_arr_pdf *)self;
//error_log("%p", l_pdf);
//error_log("%lf %lf %lf", l_pdf->origin.x, l_pdf->origin.y, l_pdf->origin.z);
//error_log("%p", l_pdf->lights);
	const int				idx = random_int_range(0, l_pdf->lights->cnt - 1);
	t_object				*light;

//error_log("%d", idx);
	light = (t_object *)(l_pdf->lights->data[idx]);
	return (light->random(light, &l_pdf->origin));
}
