#ifndef S_DYNAMIC_ARR_H
# define S_DYNAMIC_ARR_H

# include "typedef.h"

struct s_dynamic_arr
{
	void	**data;
	int		cap;
	int		cnt;
};

#endif