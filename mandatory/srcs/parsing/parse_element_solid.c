#include "parsing_internel.h"

/*
	- 현재: orient/normal vector가 -1과 1 범위 내에 있는지 확인하는 조건문만 있음
	- TODO: 
		- orient/normal vector normalize된 건지 확인하는 조건문 추가할 것
		- 위의 조건문을 추가 시 기존의 범위 확인 조건문은 필요없을 것으로 보임
		- 대상: plane, cylinder, cone
*/
int	parse_element_point_light(t_scene *scene, char *str)
{
	t_point3	pos;
	double		brightness;
	t_vector3	rgb;

	skip_until_next_value(&str);
	pos = parse_vector3(&str);
	brightness = parse_double(&str);
	rgb = parse_vector3(&str);
	if (*str != '\n')
		return (FAILURE);
	if (!is_num_in_range(brightness, 0, 1) || !is_vec3_in_range(rgb, 0, 255))
		return (FAILURE);
	if (build_element_point_light(
			&scene->world, &pos, &brightness, &rgb) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	parse_element_plane(t_scene *scene, char *str)
{
	t_point3	pos;
	t_vector3	normal;
	t_vector3	rgb;

	skip_until_next_value(&str);
	pos = parse_vector3(&str);
	normal = parse_vector3(&str);
	rgb = parse_vector3(&str);
	if (*str != '\n' && *str != '\0')
		return (FAILURE);
	if (!is_vec3_in_range(normal, -1, 1) || !is_vec3_in_range(rgb, 0, 255))
		return (FAILURE);
	if (build_element_plane(
			&scene->world, &pos, &normal, &rgb) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	parse_element_sphere(t_scene *scene, char *str)
{
	t_point3	pos;
	double		diameter;
	t_vector3	rgb;

	skip_until_next_value(&str);
	pos = parse_vector3(&str);
	diameter = parse_double(&str);
	rgb = parse_vector3(&str);
	if (*str != '\n' && *str != '\0')
		return (FAILURE);
	if (!is_vec3_in_range(rgb, 0, 255))
		return (FAILURE);
	if (build_element_sphere(
			&scene->world, &pos, &diameter, &rgb) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	parse_element_cylinder(t_scene *scene, char *str)
{
	t_parsing_info_object_cylinder	cy_parsing_info;

	skip_until_next_value(&str);
	cy_parsing_info.center = parse_vector3(&str);
	cy_parsing_info.orient = parse_vector3(&str);
	cy_parsing_info.diameter = parse_double(&str);
	cy_parsing_info.height = parse_double(&str);
	cy_parsing_info.rgb = parse_vector3(&str);
	if (*str != '\n' && *str != '\0')
		return (FAILURE);
	if (!is_vec3_in_range(cy_parsing_info.orient, -1, 1)
		|| !is_vec3_in_range(cy_parsing_info.rgb, 0, 255))
		return (FAILURE);
	cy_parsing_info.orient = v3_normalize(cy_parsing_info.orient);
	if (build_element_cylinder(
			&scene->world, &cy_parsing_info) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	parse_element_cone(t_scene *scene, char *str)
{
	t_parsing_info_object_cone	co_parsing_info;

	skip_until_next_value(&str);
	co_parsing_info.center = parse_vector3(&str);
	co_parsing_info.orient = parse_vector3(&str);
	co_parsing_info.diameter = parse_double(&str);
	co_parsing_info.height = parse_double(&str);
	co_parsing_info.rgb = parse_vector3(&str);
	if (*str != '\n' && *str != '\0')
		return (FAILURE);
	if (!is_vec3_in_range(co_parsing_info.orient, -1, 1)
		|| !is_vec3_in_range(co_parsing_info.rgb, 0, 255))
		return (FAILURE);
	co_parsing_info.orient = v3_normalize(co_parsing_info.orient);
	if (build_element_cone(
			&scene->world, &co_parsing_info) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
