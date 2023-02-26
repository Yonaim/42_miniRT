#ifndef S_TEXTURE_H
# define S_TEXTURE_H

# include "typedef.h"

enum e_texture_type
{
	TEXTURE,
	TEXTURE_SOLID,
	TEXTURE_CHECKER
};

struct s_texture
{
	t_get_texture_value	get_val;
	t_get_texture_type	get_type;
};

struct s_texture_solid
{
	t_get_texture_value	get_val;
	t_get_texture_type	get_type;
	t_color3			color;
};

struct s_texture_checker
{
	t_get_texture_value	get_val;
	t_get_texture_type	get_type;
	t_texture			*odd;
	t_texture			*even;
};

#endif