#ifndef S_PDF_H
# define S_PDF_H

# include "libmath.h"
# include "s_object.h"
# include "s_dynamic_arr.h"

typedef struct s_pdf			t_pdf;
typedef struct s_mixture_pdf	t_mixture_pdf;
typedef struct s_cosine_pdf		t_cosine_pdf;
typedef struct s_light_pdf		t_light_pdf;

typedef double					(*t_get_pdf_value)(t_pdf *self, t_vector3 dir);
typedef t_vector3				(*t_generate_random)(void);

struct s_pdf
{
	t_get_pdf_value		get_val;
	t_generate_random	generate;
};

struct s_mixture_pdf
{
	t_get_pdf_value		get_val;
	t_generate_random	generate;
};

struct s_light_pdf
{
	t_get_pdf_value		get_val;
	t_generate_random	generate;
	t_point3			origin;
	t_object_arr		*lights;
};

struct s_cosine_pdf
{
	t_get_pdf_value		get_val;
	t_generate_random	generate;
};



#endif
