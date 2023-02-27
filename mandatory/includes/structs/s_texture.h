#ifndef S_TEXTURE_H
# define S_TEXTURE_H

# include "typedef.h"

struct s_texture
{
	t_get_texture_value	get_val;
	t_destroy_texture	destroy;
};

struct s_texture_solid
{
	t_get_texture_value	get_val;
	t_destroy_texture	destroy;
	t_color3			color;
};

struct s_texture_checker
{
	t_get_texture_value	get_val;
	t_destroy_texture	destroy;
	t_texture			*odd;
	t_texture			*even;
};

struct s_texture_image
{
	t_get_texture_value	get_val;
	t_destroy_texture	destroy;
	unsigned char		*data;
	int					width;
	int					height;
	int					bytes_per_scanline;		
};

#endif