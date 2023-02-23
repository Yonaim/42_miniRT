#ifndef S_MATERIAL_H
# define S_MATERIAL_H

# include "typedef.h"

struct s_material
{
	t_scatter	scatter;
};

struct s_material_lambertian
{
r	t_scatte	scatter;
	t_color3	albedo;
}	t_material_lambertian;

struct s_material_metal
{
	t_scatter	scatter;
	t_color3	albedo;
	double		fuzz;
}	t_material_metal;

struct s_material_dielectric
{
	t_scatter	scatter;
	double		refractive_idx;
}	t_material_dielectric;

struct s_material_emmisive
{
	t_scatter	scatter;
	t_color3	albedo;
// brightness 감안하여 값 구하기
}	t_material_emmisive;

#endif