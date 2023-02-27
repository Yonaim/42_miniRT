#ifndef S_MATERIAL_H
# define S_MATERIAL_H

# include "s_texture.h"
# include "typedef.h"

struct s_material
{
	t_scatter			scattered;
	t_emit				emitted;
	t_destroy_material	destroy;
	t_scattering_pdf	s_pdf;
	t_texture			*texture;
};

struct s_material_lambertian
{
	t_scatter			scattered;
	t_emit				emitted;
	t_destroy_material	destroy;
	t_scattering_pdf	s_pdf;
	t_texture			*albedo;
};

struct s_material_metal
{
	t_scatter			scattered;
	t_emit				emitted;
	t_destroy_material	destroy;
	t_scattering_pdf	s_pdf;
	t_texture			*texture;
	t_color3			albedo;
	double				fuzz;
};

struct s_material_dielectric
{
	t_scatter			scattered;
	t_emit				emitted;
	t_destroy_material	destroy;
	t_scattering_pdf	s_pdf;
	t_texture			*texture;
	double				refractive_idx;
};

struct s_material_emmisive
{
	t_scatter			scattered;
	t_emit				emitted;
	t_destroy_material	destroy;
	t_scattering_pdf	s_pdf;
	t_texture			*emit;
// brightness 감안하여 값 구하기
};

#endif