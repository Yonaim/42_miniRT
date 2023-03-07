#ifndef S_WORLD_H
# define S_WORLD_H

# include "typedef.h"
# include "s_dynamic_arr.h"
# include "s_pdf.h"
struct s_world
{
	t_object_arr	lights;
	t_object_arr	objects;
	t_mixture_pdf	mixture_pdf;
	t_color3		background_color;
};

#endif