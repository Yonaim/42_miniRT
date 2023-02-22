#ifndef S_WORLD_H
# define S_WORLD_H

# include "s_object.h"

// typedef struct s_object_arr
// {
// 	t_object		*data;
// 	size_t			capacity;
// 	size_t			count;
// }	t_object_arr;

typedef struct s_world
{
	// t_object_arr	*objects;
	t_list			*object_list;
	t_color			background_color;
}	t_world;

#endif