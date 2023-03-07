#ifndef S_PDF_H
# define S_PDF_H

# include "libmath.h"
# include "s_object.h"
# include "s_dynamic_arr.h"

typedef struct s_pdf				t_pdf;
typedef struct s_mixture_pdf		t_mixture_pdf;
typedef struct s_cosine_pdf			t_cosine_pdf;
typedef struct s_light_arr_pdf		t_light_arr_pdf;

typedef double					(*t_get_pdf_value)(\
									const t_pdf *self, const t_vector3 *dir);
typedef t_vector3				(*t_generate_random)(const t_pdf *self);

struct s_pdf
{
	t_get_pdf_value		get_val;
	t_generate_random	generate;
};

struct s_light_arr_pdf
{
	t_get_pdf_value		get_val;
	t_generate_random	generate;
	t_point3			origin;
	t_object_arr		*lights;
	double				weight;
};

struct s_cosine_pdf
{
	t_get_pdf_value		get_val;
	t_generate_random	generate;
	t_onb				onb;
};

struct s_mixture_pdf
{
	t_get_pdf_value		get_val;
	t_generate_random	generate;
	t_light_arr_pdf		light_arr_pdf;
	t_cosine_pdf		cosine_pdf;
	t_point3			origin;
};


#endif