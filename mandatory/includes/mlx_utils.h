#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include <mlx.h>
# include "typedef.h"

t_color3	get_pixel_color(t_image *img, int x, int y);
void		put_pixel_to_image(t_image *img, int x, int y, t_color3 color);
void		init_mlx(t_mlx *mlx, t_image *img);


#endif