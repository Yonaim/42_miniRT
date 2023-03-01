#ifndef TEXTURE_H
# define TEXTURE_H

# include "typedef.h"

t_texture	*new_texture(t_info_texture *texture_info);
t_texture	*new_solid(t_color3 color);
t_texture	*new_checker_solid(t_color3 even, t_color3 odd);
t_texture	*new_checker(t_texture *even, t_texture *odd);

#endif