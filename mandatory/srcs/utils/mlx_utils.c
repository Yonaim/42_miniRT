#include "constants.h"
#include "mlx_utils.h"
#include "color.h"

void	put_pixel_to_image(t_image *img, int x, int y, t_color color)
{
	char		*dst;
	int			offset;

	if (x > img->width || y > img->height || x < 0 || y < 0)
		return ;
	offset = (y * img->bytes_per_line) + (x * (img->bits_per_pixel / 8));
	if (0 <= offset && offset < (img->width * img->height) * 4)
	{
		dst = &img->data[offset];
		*(unsigned int *)dst = albedo_to_rgb(color);
	}
}

void	init_mlx(t_mlx *mlx, t_image *img)
{
	mlx->conn = mlx_init();
	mlx->win = mlx_new_window(mlx->conn, img->width, img->height, WINDOW_NAME);
	img->obj = mlx_new_image(mlx->conn, img->width, img->height);
	img->data = mlx_get_data_addr(img->obj, &img->bits_per_pixel, \
		&img->bytes_per_line, &img->endian);
	img->data_size = img->bytes_per_line * img->height;
	img->width = img->width;
	img->height = img->height;
}
