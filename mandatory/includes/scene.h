#ifndef SCENE_H
# define SCENE_H

# include "typedef.h"

void	init_scene(t_scene *scene, t_image *img, char *path);
int		render_scene(void *minirt);
void	flush_scene(t_scene *scene);

#endif