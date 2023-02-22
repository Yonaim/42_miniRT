#ifndef S_MATERIAL_H
# define S_MATERIAL_H

# include "libmath.h"
# include "s_scatter_record.h"
# include "color.h"

typedef struct s_material	t_material;
# include "s_hit_record.h"
typedef bool				(*t_scatter)(\
							t_material *self, t_ray *ray, \
							t_hit_record *h_rec, t_scatter_record *s_rec);

struct s_material
{
	t_scatter	scatter;
};

typedef struct s_material_lambertian
{
	t_scatter	scatter;
	t_color		albedo;
}	t_material_lambertian;

typedef struct s_material_metal
{
	t_scatter	scatter;
	t_color		albedo;
	double		fuzz;
}	t_material_metal;

typedef struct s_material_dielectric
{
	t_scatter	scatter;
	double		refractive_idx;
}	t_material_dielectric;

typedef struct s_material_emmisive
{
	t_scatter	scatter;
	t_color		albedo;
	// brightness 감안하여 값 구하기
}	t_material_emmisive;

#endif