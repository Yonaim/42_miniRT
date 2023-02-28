#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include <mlx.h>
# include "typedef.h"

# define EVENT_KEY_PRESS	2
# define EVENT_DESTROY		17
# define KEY_ESC 			53

t_color3	get_pixel_color(t_image *img, int x, int y);
void		put_pixel_to_image(t_image *img, int x, int y, t_color3 color);
void		init_mlx(t_mlx *mlx);
int			destroy_hook(void *minirt);
int			keypress_hook(int keycode, void *minirt);

#endif