#ifndef S_MLX_H
# define S_MLX_H

typedef struct s_image {
	void	*obj;
	char	*data;
	int		data_size;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		bytes_per_line;
	int		endian;
}	t_image;

typedef struct s_mlx {
	void	*conn;
	void	*win;
	t_image	img;
}	t_mlx;

#endif