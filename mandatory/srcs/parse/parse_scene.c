#include "parse_internal.h"
#include <string.h>

static int	match_element_line_format(const t_token_arr *tokens)
{
	const t_is_element_line	is_element_line[] = {
	[ELEMENT_CAMERA] = is_camera_line,
	[ELEMENT_AMBIENT] = is_ambient_line,
	[ELEMENT_LIGHT] = is_point_light_line,
	[ELEMENT_SPHERE] = is_sphere_line,
	[ELEMENT_PLANE] = is_plane_line,
	[ELEMENT_TUBE] = is_tube_line,
	[ELEMENT_DISK] = is_disk_line,
	[ELEMENT_CYLINDER] = is_cylinder_line,
	[ELEMENT_CONE] = is_cone_line,
	[ELEMENT_CONE_LATERAL] = is_cone_lateral_line,
	[ELEMENT_BOX] = is_box_line,
	NULL
	};
	int						idx;

	idx = 0;
	while (idx < ELEMENT_TYPE_COUNT)
	{
		if (is_element_line[idx](tokens) == true)
			return (idx);
		idx++;
	}
	return (ELEMENT_NONE);
}

static t_info	*get_element_info(int type, const t_token_arr *tokens)
{
	const t_get_info_element get_info_elem[] = {
	[ELEMENT_CAMERA] = get_info_camera,
	[ELEMENT_AMBIENT] = get_info_ambient,
	[ELEMENT_LIGHT] = get_info_point_light,
	[ELEMENT_SPHERE] = get_info_sphere,
	[ELEMENT_PLANE] = get_info_plane,
	[ELEMENT_TUBE] = get_info_tube,
	[ELEMENT_DISK] = get_info_disk,
	[ELEMENT_CYLINDER] = get_info_cylinder,
	[ELEMENT_CONE] = get_info_cone,
	[ELEMENT_CONE_LATERAL] = get_info_cone_lateral,
	[ELEMENT_BOX] = get_info_box,
	};

	if (type == ELEMENT_NONE)
		return (NULL);
	else
		return (get_info_elem[type](tokens));
}

int	parse_line(char *line, t_info **info, int *type)
{
	const t_token_arr	*tokens = tokenize(line);

	if (tokens == NULL)
		return (FAILURE);
	if (((t_token *)tokens->data[0])->type == TOKEN_HASH)
		return (SUCCESS);
	*type = match_element_line_format(tokens);
	*info = get_element_info(*type, tokens);
	if (info == NULL)
		return (FAILURE);
	return (SUCCESS);
}

int	put_element_to_scene(t_info *info, t_scene *scene, int type)
{
	const t_put_element	put_to_scene[] = {
	[ELEMENT_AMBIENT] = put_ambient_to_scene,
	[ELEMENT_CAMERA] = put_camera_to_scene,
	[ELEMENT_LIGHT] = put_point_light_to_scene,
	[ELEMENT_PLANE] = put_plane_to_scene,
	[ELEMENT_SPHERE] = put_sphere_to_scene,
	[ELEMENT_DISK] = put_disk_to_scene,
	[ELEMENT_TUBE] = put_tube_to_scene,
	[ELEMENT_CYLINDER] = put_cylinder_to_scene,
	[ELEMENT_CONE_LATERAL] = put_cone_lateral_to_scene,
	[ELEMENT_CONE] = put_cone_to_scene,
	[ELEMENT_BOX] = put_box_to_scene,
	[ELEMENT_NONE] = NULL
	};

	return (put_to_scene[type](info, scene));
}

int	parse_scene(t_scene *scene, int fd)
{
	char		*line;
	int			type;
	t_info		*info;
	int			nth;
	bool		exist[ELEMENT_TYPE_COUNT];

	ft_memset(exist, false, sizeof(bool) * ELEMENT_TYPE_COUNT);
	line = get_next_line(fd);
	nth = 1;
	while (line)
	{
		if (parse_line(line, &info, &type) == FAILURE)
		{
			printf("Error: parse %dth line failed\n", nth);
			exit(1); // handle_error 함수 호출하여 에러 처리하도록 수정
		}
		if (is_must_be_one_element_type(type) && exist[type] == true)
			handle_error("Error: duplicated declaration");
		put_element_to_scene(info, scene, type);
		exist[type] = true;
		line = get_next_line(fd);
		nth++;
	}
	if (is_must_be_elements_exist(exist) == false)
		handle_error("Error: There is no element that must exist");
	return (SUCCESS);
}
