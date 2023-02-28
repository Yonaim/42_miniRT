#include <mlx.h>
#include "libft.h"
#include "constants.h"
#include "s_mlx.h"
#include "s_minirt.h"
#include "mlx_utils.h"
#include "scene.h"
#include "color.h"

t_color3	get_pixel_color(t_image *img, int x, int y)
{
	char		*dst;
	int			offset;

	if (x > img->width || y > img->height || x < 0 || y < 0)
		return (color3(0, 0, 0));
	offset = (y * img->bytes_per_line) + (x * (img->bits_per_pixel / 8));
	if (offset <= 0 || offset > (img->width * img->height) * 4)
		return (color3(0, 0, 0));
	dst = &img->data[offset];
	return (rgb_to_color3(*(unsigned int *)dst));
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

void	init_mlx(t_mlx *mlx)
{
	t_image	*img;
	
	img = &mlx->img;
	mlx->conn = mlx_init();
	mlx->win = mlx_new_window(mlx->conn, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
	img->width = WINDOW_WIDTH;
	img->height = WINDOW_HEIGHT;
	img->obj = mlx_new_image(mlx->conn, img->width, img->height);
	img->data = mlx_get_data_addr(img->obj, &img->bits_per_pixel, \
							&img->bytes_per_line, &img->endian);
	img->data_size = img->bytes_per_line * img->height;
	ft_memset(img->data, 0, img->width * img->height * img->bits_per_pixel / 8);
}

int	destroy_hook(void *minirt)
{
	flush_scene(&((t_minirt *)minirt)->scene);
	exit(0);
}

int	keypress_hook(int keycode, void *minirt)
{
	if (keycode == KEY_ESC)
	{
		flush_scene(&((t_minirt *)minirt)->scene);
		exit(0);
	}
	return (0);
}