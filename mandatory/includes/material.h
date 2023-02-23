#ifndef MATERIAL_H
# define MATERIAL_H

# include "s_hit_record.h"
# include "s_scatter_record.h"
# include "typedef.h"

t_material_dielectric	*create_dielectric(double refractive_idx);
t_material_lambertian	*create_lambertian(t_color3 albedo);
t_material_metal		*create_metal(t_color3 albedo, double fuzz);

#endif