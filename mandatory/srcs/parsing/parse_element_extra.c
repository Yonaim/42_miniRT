#include "parsing_internel.h"

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
	scene->cam.basis.dir = v3_mul(orient, -1);
	scene->cam.viewport.fov = fov;
	return (SUCCESS);
}
