#include "parsing_internel.h"

int	parse_element_light(t_ray_tracing *rt, char *str)
{
	t_point3	pos;
	double		ratio;
	t_vector3	rgb;

	pos = parse_vector3(&str);
	ratio = parse_double(&str);
	rgb = vector3(255, 255, 255);
	rgb = parse_vector3(&str);
	if (*str != '\n')
		return (FAILURE);
	if (!is_num_in_range(ratio, 0, 1) || !is_vec3_in_range(rgb, 0, 255))
		return (FAILURE);
	if (add_to_object_list(&rt->world.object_list, \
							create_light(pos, ratio, rgb)) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	parse_element_plane(t_ray_tracing *rt, char *str)
{
	t_point3	pos;
	t_vector3	normal;
	t_vector3	rgb;

	pos = parse_vector3(&str);
	normal = parse_vector3(&str);
	rgb = parse_vector3(&str);
	if (*str != '\n' && *str != '\0')
		return (FAILURE);
	if (!is_vec3_in_range(normal, -1, 1) || !is_vec3_in_range(rgb, 0, 255))
		return (FAILURE);
	if (add_to_object_list(&rt->world.object_list, \
							create_plane(pos, normal, rgb)) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	parse_element_sphere(t_ray_tracing *rt, char *str)
{
	t_point3	pos;
	double		diameter;
	t_vector3	rgb;

	pos = parse_vector3(&str);
	diameter = parse_double(&str);
	rgb = parse_vector3(&str);
	if (*str != '\n' && *str != '\0')
		return (FAILURE);
	if (!is_vec3_in_range(rgb, 0, 255))
		return (FAILURE);
	if (add_to_object_list(&rt->world.object_list, \
							create_sphere(pos, diameter / 2, rgb)) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	parse_element_cylinder(t_ray_tracing *rt, char *str)
{
	t_point3	center;
	t_vector3	orient;
	double		diameter;
	double		height;
	t_vector3	rgb;

	skip_char(&str, ' ');
	center = parse_vector3(&str);
	orient = parse_vector3(&str);
	diameter = parse_double(&str);
	height = parse_double(&str);
	rgb = parse_vector3(&str);
	if (*str != '\n' && *str != '\0')
		return (FAILURE);
	if (!is_vec3_in_range(orient, -1, 1) || !is_vec3_in_range(rgb, 0, 255))
		return (FAILURE);
	if (add_to_object_list(&rt->world.object_list, \
		create_cylinder(center, orient, diameter / 2, height, rgb)) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}