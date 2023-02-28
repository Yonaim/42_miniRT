#ifndef S_MINIRT_H
# define S_MINIRT_H

# include "typedef.h"
# include "s_mlx.h"
# include "s_scene.h"

struct s_render_status
{
	bool	is_done;
	int		layer_cnt;
};

struct s_minirt
{
	t_mlx			mlx;
	t_scene			scene;
	t_render_status	status;
};

#endif
