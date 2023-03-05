#ifndef S_MLX_H
# define S_MLX_H

# include "color.h"
# include "typedef.h"

struct s_image
{
	void		*obj;
	char		*data;
	t_color3	*tmp_data;
	int			data_size;
	int			width;
	int			height;
	int			bits_per_pixel;
	int			bytes_per_line;
	int			endian;
};

struct s_mlx
{
	void	*conn;
	void	*win;
	t_image	img;
};

#endif