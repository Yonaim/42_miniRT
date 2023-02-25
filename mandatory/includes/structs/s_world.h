#ifndef S_WORLD_H
# define S_WORLD_H

# include "typedef.h"

struct s_world
{
	t_object	**objects;
	int			cap;
	int			cnt;
	t_color3	background_color;
};

#endif