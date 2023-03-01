#include <mlx.h>
#include "libft.h"
#include "constants.h"
#include "s_mlx.h"
#include "s_minirt.h"
#include "mlx_utils.h"
#include "scene.h"
#include "color.h"
#include "handle_error.h"

void	put_pixel_to_image(t_image *img, t_color3 *color, int x, int y)
{
	char	*dst;
	int		offset;

	if (x > img->width || y > img->height || x < 0 || y < 0)
		return ;
	offset = (y * img->bytes_per_line) + (x * (img->bits_per_pixel / 8));
	if (0 <= offset && offset < (img->width * img->height) * 4)
	{
		dst = &img->data[offset];
		*(unsigned int *)dst = color3_to_rgb(color);
	}
}

void	init_mlx(t_mlx *mlx)
{
	t_image	*img;

	img = &mlx->img;
	mlx->conn = mlx_init();
	mlx->win = mlx_new_window(\
					mlx->conn, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
	img->width = WINDOW_WIDTH;
	img->height = WINDOW_HEIGHT;
	img->obj = mlx_new_image(mlx->conn, img->width, img->height);
	img->data = mlx_get_data_addr(img->obj, &img->bits_per_pixel, \
							&img->bytes_per_line, &img->endian);
	img->buff = ft_calloc(img->height * img->width, sizeof(char));
	img->data_size = img->bytes_per_line * img->height;
	ft_memset(img->data, 0, img->width * img->height * img->bits_per_pixel / 8);
}

