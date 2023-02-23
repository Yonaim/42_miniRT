#ifndef S_HIT_RECORD_H
# define S_HIT_RECORD_H

# include <stdbool.h>
# include "libmath.h"
# include "constants.h"

typedef struct s_material	t_material;

typedef struct s_hit_record
{
	double		t;
	t_point3	p;
	t_vector3	normal;
	t_material	*material;
	bool		opposed;
}	t_hit_record;

#endif