#ifndef MATERIAL_H
# define MATERIAL_H

# include "s_info_element.h"
# include "s_hit_record.h"
# include "s_scatter_record.h"
# include "typedef.h"

t_material	*new_material(const t_info_material *material_info);
t_material	*new_lambertian(t_texture *texture);
t_material	*new_dielectric(double refractive_idx);
t_material	*new_metal(t_texture *texture, double fuzz);
t_material	*new_emmisive(t_color3 rgb);
t_material	*new_random_material(void);

#endif