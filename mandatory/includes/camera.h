#ifndef CAMERA_H
# define CAMERA_H

# include "s_ray.h"
# include "s_camera.h"

t_ray	primary_ray(t_camera *cam, double u, double v);
void	init_camera(t_camera *cam);

#endif
