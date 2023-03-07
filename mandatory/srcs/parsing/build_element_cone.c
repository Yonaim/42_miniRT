#include "parsing_internel.h"

void	_build_element_cone_lateral(
		t_info_object_cone *co_info,
		t_parsing_info_object_cone *co_parsing_info)
{
	co_info->lateral.center = co_parsing_info->center;
	co_info->lateral.orient = co_parsing_info->orient;
	co_info->lateral.radius = co_parsing_info->diameter / 2;
	co_info->lateral.height = co_parsing_info->height;
	co_info->lateral.material = co_info->material;
	co_info->lateral.texture = co_info->texture;
}

void	_build_element_cone_disk(
		t_info_object_cone *co_info,
		t_parsing_info_object_cone *co_parsing_info)
{
	co_info->disk.center = co_parsing_info->center;
	co_info->disk.radius = co_info->lateral.radius;
	co_info->disk.normal = co_parsing_info->orient;
	co_info->disk.material = co_info->material;
	co_info->disk.texture = co_info->texture;
}

int	build_element_cone(
	t_world *world,
	t_parsing_info_object_cone *co_parsing_info)
{
	t_info_object_cone	co_info;

	co_info.material.type = MATERIAL_LAMBERTIAN;
	co_info.texture.type = TEXTURE_SOLID;
	co_info.texture.rgb1 = co_parsing_info->rgb;
	_build_element_cone_lateral(&co_info, co_parsing_info);
	_build_element_cone_disk(&co_info, co_parsing_info);
	if (add_object_to_world(world, new_cone(&co_info)) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
