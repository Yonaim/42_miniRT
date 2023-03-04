#include "parse_internal.h"
#include <string.h>

static int	match_element_line_format(const t_token_arr *tokens)
{
	const t_is_element_line	is_element_line[] = {
	[ELEMENT_CAMERA] = is_camera_line,
	[ELEMENT_AMBIENT] = is_ambient_line,
	[ELEMENT_LIGHT] = is_light_line,
	[ELEMENT_SPHERE] = is_sphere_line,
	[ELEMENT_PLANE] = is_plane_line,
	[ELEMENT_CYLINDER] = is_cylinder_line,
	[ELEMENT_CONE] = is_cone_line,
	[ELEMENT_BOX] = is_box_line,
	};
	int						idx;

	idx = 0;
	while (idx < ELEMENT_TYPE_COUNT)
	{
		if (is_element_line[idx](tokens) == true)
			return (idx);
		idx++;
	}
	return (-1);
}

static int	add_element(int type, const t_token_arr *tokens)
{
	// const t_get_info_element get_info_elem[] = {
	// [ELEMENT_CAMERA] = get_info_camera,
	// [ELEMENT_AMBIENT] = get_info_ambient,
	// [ELEMENT_LIGHT] = get_info_light,
	// [ELEMENT_SPHERE] = get_info_sphere,
	// [ELEMENT_PLANE] = get_info_plane,
	// [ELEMENT_CYLINDER] = get_info_cylinder,
	// [ELEMENT_CONE] = get_info_cone,
	// [ELEMENT_BOX] = get_info_box,
	// };
	// const t_info			*elem_info = get_info_elem[type](tokens);

	// if (elem_info == NULL)
	// 	return (FAILURE);
	type++;
	tokens++;
	return (SUCCESS);
}

static int	parse_line(t_scene *scene, char *line, bool elem_exist[])
{

	const t_token_arr		*tokens = tokenize(line);
	int						type;

scene++;
	if (tokens == NULL)
		return (FAILURE);
	if (((t_token *)tokens->data[0])->type == TOKEN_HASH)
		return (SUCCESS);
		// 맨 처음 토큰이 해쉬(#)일 경우 주석으로 간주
		// 이후 is_valid_formatted_line에서 해쉬 토큰 관련 검사를 제대로 수행할 경우 빼도 됨
	type = match_element_line_format(tokens);
	if (type == -1)
		return (FAILURE);
	if (is_must_be_one_element_type(type) == true \
		&& elem_exist[type] == true)
		handle_error("Duplicate element exists that must exist only one.");
	if (add_element(type, tokens) == FAILURE)
		return (FAILURE);
	elem_exist[type] = true;
	return (SUCCESS);
}

int	parse_scene(t_scene *scene, char *path)
{
	const int	fd = open(path, O_RDONLY);
	char		*line;
	bool		elem_exist[ELEMENT_TYPE_COUNT];

	if (fd < 0)
		return (FAILURE);
	ft_memset(elem_exist, false, sizeof(bool) * ELEMENT_TYPE_COUNT);
	line = get_next_line(fd);
	while (line)
	{
		if (parse_line(scene, line, elem_exist) == FAILURE)
			return (FAILURE);
		line = get_next_line(fd);
	}
	if (is_must_be_elements_exist(elem_exist) == false)
		handle_error("There is no element that must exist.");
	return (SUCCESS);
}
