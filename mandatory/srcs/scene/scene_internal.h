#ifndef SCENE_INTERNAL_H
# define SCENE_INTERNAL_H

// standard library
# include <math.h>
// extra
# include "constants.h"
# include "handle_error.h"
# include "typedef.h"
// structures
# include "s_minirt.h"
# include "s_scene.h"
# include "s_mlx.h"
# include "s_hit_record.h"
# include "s_scatter_record.h"
# include "s_material.h"
# include "s_object.h"
# include "s_ray.h"
// prototypes
# include "mlx_utils.h"
# include "ray.h"
# include "parsing.h"
# include "camera.h"
# include "object_arr.h"
# include "color.h"

void		gamma_correction(t_color3 *color);
t_color3	traced_color(t_ray *in_ray, t_world *world, int depth);
void		get_sampled_color(\
				t_color3 *sampled_color, t_scene *scene, int x, int y);
void		calculate_average_color(\
				t_color3 *stored_color, t_color3 *sampled_color, \
				int stored_cnt);
void		get_stored_color(\
				t_color3 *stored_color, t_image *img, int x, int y);
void		update_stored_color(\
				t_image *img, t_color3 *stored_color, int x, int y);
#endif