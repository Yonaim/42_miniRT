#ifndef MATERIAL_H
# define MATERIAL_H

# include "s_hit_record.h"
# include "s_scatter_record.h"
# include "typedef.h"

t_material	*new_dielectric(double refractive_idx);
t_material	*new_lambertian(t_color3 albedo);
t_material	*new_metal(t_color3 albedo, double fuzz);

#endif