#ifndef S_HIT_RECORD_H
# define S_HIT_RECORD_H

# include <stdbool.h>
# include "libmath.h"
# include "typedef.h"
# include "constants.h"

struct s_hit_record
{
	double		t;
	t_point3	p;
	t_vector3	normal;
	t_material	*material;
	bool		opposed;
};

#endif