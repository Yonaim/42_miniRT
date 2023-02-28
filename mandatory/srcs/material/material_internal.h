#ifndef MATERIAL_INTERNAL_H
# define MATERIAL_INTERNAL_H

# define __USE_MISC

// standard library
# include <stdbool.h>
# include <math.h>
# include <stdlib.h>

// user defined library
# include "libmath.h"

// structure
# include "typedef.h"
# include "s_scatter_record.h"
# include "s_hit_record.h"
# include "s_material.h"
# include "s_texture.h"

// prototype
# include "ray.h"
# include "texture.h"

t_material	*new_lambertian(t_texture *texture);
t_material	*new_dielectric(double refractive_idx);
t_material	*new_metal(t_texture *texture, double fuzz);
t_material	*new_emmisive(t_color3 color);
t_material	*new_random_material(void);

#endif