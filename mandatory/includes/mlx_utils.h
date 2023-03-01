#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include "mlx.h"
# include "typedef.h"

# define EVENT_KEY_PRESS	2
# define EVENT_DESTROY		17
# define KEY_ESC 			53

void	put_pixel_to_image(t_image *img, t_color3 *color, int x, int y);
void	init_mlx(t_mlx *mlx);
int		destroy_hook(void *minirt);
int		keypress_hook(int keycode, void *minirt);

#endif