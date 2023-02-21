#ifndef S_HIT_RECORD_H
# define S_HIT_RECORD_H

# include <stdbool.h>
# include "libmath.h"
# include "constant.h"
# include "s_material.h"

typedef struct s_hit_record
{
	double		t;
	t_point		p;
	t_vector	normal;
	t_material	*material;
	bool		opposed;
}	t_hit_record;

#endif