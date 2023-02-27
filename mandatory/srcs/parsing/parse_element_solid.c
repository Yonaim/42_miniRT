#include "parsing_internel.h"

int	parse_element_point_light(t_scene *scene, char *str)
{
	t_point3	pos;
	double		ratio;
	t_vector3	rgb;

	skip_until_next_value(&str);
	pos = parse_vector3(&str);
	ratio = parse_double(&str);
	rgb = vector3(255, 255, 255);
	rgb = parse_vector3(&str);
	if (*str != '\n')
		return (FAILURE);
	if (!is_num_in_range(ratio, 0, 1) || !is_vec3_in_range(rgb, 0, 255))
		return (FAILURE);
	if (add_object(&scene->world.objects, \
							new_point_light(pos, ratio, rgb)) == FAILURE)
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
	if (add_object(&scene->world.objects, \
							new_plane(pos, normal, rgb)) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	parse_element_sphere(t_scene *scene, char *str)
{
	t_point3	pos;
	double		diameter;
	// t_texture	*texture;
	t_material	*material;
	t_vector3	rgb;

	skip_until_next_value(&str);
	pos = parse_vector3(&str);
	diameter = parse_double(&str);
	rgb = parse_vector3(&str);
	if (*str != '\n' && *str != '\0')
		return (FAILURE);
	if (!is_vec3_in_range(rgb, 0, 255))
		return (FAILURE);
	// texture = new_solid(v3_div(rgb, 256));
	// material = new_lambertian(texture);
	material = new_random_material();
	if (add_object(&scene->world.objects, \
							new_sphere(pos, diameter / 2, material)) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	parse_element_cylinder(t_scene *scene, char *str)
{
	t_info_object_cylinder	cy_info;
	t_point3				center;
	t_vector3				orient;
	double					diameter;
	double					height;
	t_vector3				rgb;

	(void)scene;
	skip_until_next_value(&str);
	center = parse_vector3(&str);
	orient = parse_vector3(&str);
	diameter = parse_double(&str);
	height = parse_double(&str);
	rgb = parse_vector3(&str);
	if (*str != '\n' && *str != '\0')
		return (FAILURE);
	if (!is_vec3_in_range(orient, -1, 1) || !is_vec3_in_range(rgb, 0, 255))
		return (FAILURE);
	cy_info.material.type = MATERIAL_LAMBERTIAN;
	cy_info.texture.type = TEXTURE_SOLID;
	cy_info.texture.rgb1 = rgb;
	//tube
	cy_info.tube.center = center;
	cy_info.tube.height = height;
	cy_info.tube.orient = orient;
	cy_info.tube.radius = diameter / 2;
	cy_info.tube.material = cy_info.material;
	cy_info.tube.texture = cy_info.texture;
	// disk
	cy_info.disk[0].center = v3_sub(center, v3_mul(orient, height / 2));
	cy_info.disk[0].radius = cy_info.tube.radius;
	cy_info.disk[0].normal = orient;
	cy_info.disk[0].material = cy_info.material;
	cy_info.disk[0].texture = cy_info.texture;
	cy_info.disk[1].center = v3_add(center, v3_mul(orient, height / 2));
	cy_info.disk[1].radius = cy_info.tube.radius;
	cy_info.disk[1].normal = orient;
	cy_info.disk[1].texture = cy_info.texture;
	cy_info.disk[1].material = cy_info.material;
	if (add_object(&scene->world.objects,
					new_cylinder(&cy_info)) == FAILURE)
		return (FAILURE);
	(void)height;
	(void)diameter;
	(void)center;
	return (SUCCESS);
}