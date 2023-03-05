#include "parsing_internel.h"

/*
	- 현재: orient/normal vector가 -1과 1 범위 내에 있는지 확인하는 조건문만 있음
	- TODO: 
		- orient/normal vector normalize된 건지 확인하는 조건문 추가할 것
		- 위의 조건문을 추가 시 기존의 범위 확인 조건문은 필요없을 것으로 보임
		- 대상: plane, cylinder, box
*/

int	parse_element_box(t_scene *scene, char *str)
{
	t_vector3	p_end1;
	t_vector3	p_end2;
	t_color3	rgb;

	skip_until_next_value(&str);
	p_end1 = parse_vector3(&str);
	p_end2 = parse_vector3(&str);
	rgb = parse_vector3(&str);
	if (*str != '\n' && *str != '\0')
		return (FAILURE);
	if (build_element_box(
			&scene->world.objects, &p_end1, &p_end2, &rgb) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
