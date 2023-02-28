#ifndef S_MATERIAL_H
# define S_MATERIAL_H

# include "typedef.h"

struct s_material
{
	t_scatter			scattered;
	t_emit				emitted;
	t_destroy_material	destroy;
	t_scattering_pdf	s_pdf;
	t_get_material_type	get_type;
};

struct s_material_lambertian
{
	t_scatter			scattered;
	t_emit				emitted;
	t_destroy_material	destroy;
	t_scattering_pdf	s_pdf;
	t_get_material_type	get_type;
	t_texture			*albedo;
};

struct s_material_metal
{
	t_scatter			scattered;
	t_emit				emitted;
	t_destroy_material	destroy;
	t_scattering_pdf	s_pdf;
	t_get_material_type	get_type;
	t_color3			albedo;
	double				fuzz;
};

struct s_material_dielectric
{
	t_scatter			scattered;
	t_emit				emitted;
	t_destroy_material	destroy;
	t_scattering_pdf	s_pdf;
	t_get_material_type	get_type;
	double				refractive_idx;
};

struct s_material_emmisive
{
	t_scatter			scattered;
	t_emit				emitted;
	t_destroy_material	destroy;
	t_scattering_pdf	s_pdf;
	t_get_material_type	get_type;
	t_texture			*emit;
// brightness 감안하여 값 구하기
};

#endif