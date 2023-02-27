#ifndef SCENE_H
# define SCENE_H

# include "typedef.h"

void	init_scene(t_scene *scene, t_image *img, char *path);
void	render_scene(t_mlx *mlx, t_scene *scene);
void	flush_scene(t_scene *scene);

#endif