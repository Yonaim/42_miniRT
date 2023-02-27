#ifndef S_OBJECT_ARR_H
# define S_OBJECT_ARR_H

# include "typedef.h"

struct s_object_arr
{
	t_object	**arr;
	int			cap;
	int			cnt;
};

#endif