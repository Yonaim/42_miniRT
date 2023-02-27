#ifndef DYNAMIC_ARR_H
# define DYNAMIC_ARR_H

# include "s_dynamic_arr.h"
# include "typedef.h"

int				init_dynamic_arr(t_dynamic_arr *darr, int cap);
t_dynamic_arr	*new_dynamic_arr(int cap);
void			clear_dynamic_arr(t_dynamic_arr *darr);
void			destroy_dynamic_arr(t_dynamic_arr *darr);
int				push_back_dynamic_arr(t_dynamic_arr *darr, void *data);

#endif