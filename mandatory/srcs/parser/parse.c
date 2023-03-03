#include "parser.h"
#include <string.h>

// 토큰 배열을 받아서 식별자(word 토큰)를 확인한다
	// 맨 처음 토큰이 word 토큰이 아니거나, 유효한 식별자가 아닌 경우 바로 에러 처리
// 식별자에 따라 알맞은 info 구조체 생성 함수를 호출

static int	add_element(t_scene *scene, char *line, int elem_exist[])
{
	const t_get_info	get_info_func[] = {
	[ELEMENT_AMBIENT] = get_info_ambient,
	[ELEMENT_CAMERA] = get_info_camera,
	[ELEMENT_LIGHT] = get_info_light,
	[ELEMENT_PLANE] = get_info_plane,
	[ELEMENT_SPHERE] = get_info_sphere,
	[ELEMENT_CYLINDER] = get_info_cylinder,
	[ELEMENT_CONE] = get_info_cone
	};
	const t_token		*tokens = tokenize(line);
	const int			type = get_element_type(&tokens[0]);
	void				*info;

	if (type == ELEMENT_NONE)
		return (FAILURE);
	if (get_info_func[type](tokens) == FAILURE)
		return (FAILURE);

	elem_exist[type] = 1;
	return (SUCCESS);
}

int	parser(t_scene *scene, char *path)
{
	const int	fd = open(path, O_RDONLY);
	char		*line;
	int			elem_exist[ELEMENT_COUNT];

	if (fd < 0)
		return (FAILURE);
	ft_memset(elem_exist, 0, sizeof(int) * ELEMENT_COUNT);
	line = get_next_line(fd);
	while (line)
	{
		if (is_empty_string(line) || is_comment(line))
			continue ;
		if (add_element(scene, line, elem_exist) == FAILURE)
			return (FAILURE);
		line = get_next_line(fd);
	}
	if (elem_exist[ELEMENT_AMBIENT] == 0 \
		|| !elem_exist[ELEMENT_CAMERA] == 0 \
		|| !elem_exist[ELEMENT_LIGHT] == 0)
		return (FAILURE);
	return (SUCCESS);
}
