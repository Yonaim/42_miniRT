#ifndef S_MATERIAL_H
# define S_MATERIAL_H

# include "libmath.h"
# include "color.h"

enum e_material_type
{
	LAMBERTIAN,
	METAL,
	DIELECTRIC,
	EMMISIVE
};

typedef struct s_lambertian
{
	t_color	albedo;
}	t_lambertian;

typedef struct s_metal
{
	t_color	albedo;
	double	fuzz;
}	t_metal;

typedef struct s_dielectric
{
	double	refractive_idx;
}	t_dielectric;

typedef struct s_emmisive
{
	t_color	albedo;	// brightness 감안하여 값 구하기
}	t_emmisive;

typedef union u_material_data
{
	t_lambertian	lambertian;
	t_metal			metal;
	t_dielectric	dielectric;
	t_emmisive		emmisive;
}	t_material_data;

typedef struct s_material
{
	int				type;
	t_material_data	data;
}	t_material;

#endif