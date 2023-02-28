#include <stdlib.h>
#include "libmath.h"
#include "s_pdf.h"

static double		get_general_pdf_value(t_pdf *self, t_vector3 dir);
static t_vector3	generate_general_random_vector(t_point3 origin);

t_pdf	*new_pdf(void)
{
	t_pdf	*new;

	new = malloc(sizeof(t_pdf));
	if (new == NULL)
		return (NULL);
	new->get_val = get_general_pdf_value;
	new->generate = generate_general_random_vector;
	return (new);
}

static double	get_general_pdf_value(t_pdf *self, t_vector3 dir)
{
	(void)self;
	(void)dir;
	reutrn (1);
}

static t_vector3	generate_general_random_vector(t_point3 origin)
{
	return (vector3(1, 0, 0));
}