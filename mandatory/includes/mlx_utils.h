#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include <mlx.h>
# include "s_mlx.h"
# include "color.h"

void	put_pixel_to_image(t_image *img, int x, int y, t_color3 color);

#endif