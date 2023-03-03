#include "parsing_internel.h"

/*
	- 현재: orient vector가 -1과 1 범위 내에 있는지 확인하는 조건문만 있음
	- TODO: 
		- orient vector normalize된 건지 확인하는 조건문 추가할 것
		- 위의 조건문을 추가 시 기존의 범위 확인 조건문은 필요없을 것으로 보임
*/
int	parse_element_ambient(t_scene *scene, char *str)
{
	double		ratio;
	t_vector3	rgb;

	skip_until_next_value(&str);
	ratio = parse_double(&str);
	rgb = parse_vector3(&str);
	if (*str != '\n' && *str != '\0')
		return (FAILURE);
	if (!is_num_in_range(ratio, 0, 1) || !is_vec3_in_range(rgb, 0, 255))
		return (FAILURE);
	scene->world.background_color = (t_color3)v3_mul(rgb, ratio / 255);
	return (SUCCESS);
}

int	parse_element_camera(t_scene *scene, char *str)
{
	t_point3	origin;
	t_vector3	orient;
	int			fov;

	skip_until_next_value(&str);
	origin = parse_vector3(&str);
	orient = parse_vector3(&str);
	fov = parse_integer(&str);
	if (*str != '\n' && *str != '\0')
		return (FAILURE);
	if (!is_vec3_in_range(orient, -1, 1) || !is_num_in_range(fov, 0, 180))
		return (FAILURE);
	scene->cam.origin = origin;
	scene->cam.basis.dir = v3_normalize(v3_mul(orient, -1));
	scene->cam.viewport.fov = fov;
	return (SUCCESS);
}
