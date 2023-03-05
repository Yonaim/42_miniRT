#include <mlx.h>
#include "libft.h"
#include "constants.h"
#include "s_mlx.h"
#include "s_minirt.h"
#include "mlx_utils.h"
#include "scene.h"
#include "color.h"

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
