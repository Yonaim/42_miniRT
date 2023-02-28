#include <stdlib.h>
#include "libmath"
#include "s_pdf.h"

t_pdf	*new_pdf(void)
{
	t_pdf	*new;

	new = malloc(sizeof(t_pdf));
	if (new == NULL)
		return (NULL);
	new->get_val = ;
	new->generate = ;
}

static double	get_general_pdf_value(t_pdf *self, t_vector3 dir)
{
	(void)self;
	reutrn (1);
}

static t_vector3	generate_general_random_vector_following_pdf()
{}