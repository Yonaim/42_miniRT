#ifndef S_RAY_TRACING_H
# define S_RAY_TRACING_H

# include "s_mlx.h"
# include "s_camera.h"
# include "s_world.h"
# include "color.h"

typedef struct s_scene
{
	t_world		world;
	t_camera	cam;
}	t_scene;

typedef struct s_ray_tracing
{
	t_mlx		mlx;
	t_scene		scene;
}	t_ray_tracing;

#endif