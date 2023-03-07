#include "parsing_internel.h"

// while문 돌면서 파일 한 줄씩 읽기(get next line)
	// object 추가하고(sphere, ..., light)
	// scene->mlx.img width, height 초기화
	// camera 초기화
	// background_color 초기화
// 에러 처리
	// camera, background_color, light는 무조건 한 개만 처리

// 파일의 끝에 도달할 때까지 읽는다
// 한 줄을 읽으면 타입을 판별하며, 해당 타입에 맞는 함수를 호출해 파싱
	// 아무것도 없는 빈 줄인 경우는 그냥 넘긴다
	// invalid할 경우 failure 리턴

static bool	is_empty_string(char *str)
{
	skip_char(&str, ' ');
	if (*str == '\n')
		return (true);
	else
		return (false);
}

static int	get_element_type(char *str)
{
	skip_char(&str, ' ');
	if (*str == 'A')
		return (AMBIENT);
	else if (*str == 'C')
		return (CAMERA);
	else if (*str == 'L')
		return (LIGHT);
	else if (*str == 'p' && *(str + 1) == 'l')
		return (PLANE);
	else if (*str == 's' && *(str + 1) == 'p')
		return (SPHERE);
	else if (*str == 'c' && *(str + 1) == 'y')
		return (CYLINDER);
	else if (*str == 'c' && *(str + 1) == 'o')
		return (CONE);
	return (NONE);
}

static int	parse_element_info(t_scene *scene, char *str, int elem_exist[])
{
	const t_parse_element	parse_func[] = {
	[AMBIENT] = parse_element_ambient,
	[CAMERA] = parse_element_camera,
	[LIGHT] = parse_element_point_light,
	[PLANE] = parse_element_plane,
	[SPHERE] = parse_element_sphere,
	[CYLINDER] = parse_element_cylinder,
	[CONE] = parse_element_cone
	};
	const int				elem_type = get_element_type(str);

	if (elem_type == NONE)
		return (FAILURE);
	// if ((elem_type == AMBIENT || elem_type == CAMERA || elem_type == LIGHT) \
	// 												&& elem_exist[elem_type])
	if ((elem_type == AMBIENT || elem_type == CAMERA) \
													&& elem_exist[elem_type])
		return (FAILURE);
	if (parse_func[elem_type](scene, str) == FAILURE)
		return (FAILURE);
	elem_exist[elem_type] = 1;
	return (SUCCESS);
}

int	parse_scene(t_scene *scene, char *path)
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
		if (is_empty_string(line))
			continue ;
		if (parse_element_info(scene, line, elem_exist) == FAILURE)
			return (FAILURE);
		line = get_next_line(fd);
	}
	if (!elem_exist[AMBIENT] || !elem_exist[CAMERA] || !elem_exist[LIGHT])
		return (FAILURE);
	printf("parsing done!\n");
	return (SUCCESS);
}

// void	print_vector3(t_vector3 v)
// {
// 	printf("x: %f, y: %f, z: %f\n", v.x, v.y, v.z);
// }

// int main(int argc, char *argv[])
// {
// 	t_ray_tracing	scene;

// 	if (argc != 2)
// 		return 1;

// 	// TEST: Function is_empty_string
// 	// printf("%d\n", is_empty_string("  \ng"));

// 	// TEST: Function get_element_type
// 	// printf("%d\n", get_element_type("  pl"));

// 	// TEST: Function parse_scene_info
// 	if (parse_scene_info(&scene, argv[1]) == FAILURE)
// 		printf("Error: failed to parse scene info.\n");
// 	print_vector3(scene.world.background_color);
// }

// gnl 마지막 줄의 경우 개행이 없을 수도 있는지 확인 필요함
