#include "constants.h"
#include "s_mlx.h"
#include "color.h"

static void	init_image(t_mlx *mlx, t_image *img);

t_color3	get_pixel_color(t_image *img, int x, int y)
{
	char		*dst;
	int			offset;

	if (x > img->width || y > img->height || x < 0 || y < 0)
		return (color3(0, 0, 0));
	offset = (y * img->bytes_per_line) + (x * (img->bits_per_pixel / 8));
	dst = &img->data[offset];
	return (rgb_to_color3((unsigned int)(*dst)));
}

void	put_pixel_to_image(t_image *img, int x, int y, t_color3 color)
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

void	init_mlx(t_mlx *mlx, t_image *img)
{
	mlx->conn = mlx_init();
	mlx->win = mlx_new_window(mlx->conn, img->width, img->height, WINDOW_NAME);
	init_image(mlx, img);
}

static void	init_image(t_mlx *mlx, t_image *img)
{
	img->width = WINDOW_WIDTH;
	img->height = WINDOW_HEIGHT;
	img->obj = mlx_new_image(mlx->conn, img->width, img->height);
	img->data = mlx_get_data_addr(img->obj, &img->bits_per_pixel, \
							&img->bytes_per_line, &img->endian);
	img->data_size = img->bytes_per_line * img->height;
	ft_memset(img->data, 0, img->width * img->height * img->bits_per_pixel / 8);
}
