#ifndef MATERIAL_H
# define MATERIAL_H

# include "typedef.h"

t_material	*new_lambertian(t_texture *texture);
t_material	*new_dielectric(double refractive_idx);
t_material	*new_metal(t_color3 albedo, double fuzz);
t_material	*new_emmisive(t_color3 color);

#endif