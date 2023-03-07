#include "parsing_internel.h"

static void	_build_element_cylinder_tube(
			t_info_object_cylinder *cy_info,
			t_parsing_info_object_cylinder *cy_parsing_info)
{
	cy_info->tube.center = cy_parsing_info->center;
	cy_info->tube.height = cy_parsing_info->height;
	cy_info->tube.orient = cy_parsing_info->orient;
	cy_info->tube.radius = cy_parsing_info->diameter / 2;
	cy_info->tube.material = cy_info->material;
	cy_info->tube.texture = cy_info->texture;
}

static void	_build_element_cylinder_disks(
			t_info_object_cylinder *cy_info,
			t_parsing_info_object_cylinder *cy_parsing_info)
{
	cy_info->disk[0].center = v3_sub(cy_parsing_info->center, \
								v3_mul(cy_parsing_info->orient, \
									cy_parsing_info->height / 2));
	cy_info->disk[0].radius = cy_info->tube.radius;
	cy_info->disk[0].normal = cy_parsing_info->orient;
	cy_info->disk[0].material = cy_info->material;
	cy_info->disk[0].texture = cy_info->texture;
	cy_info->disk[1].center = v3_add(cy_parsing_info->center, \
								v3_mul(cy_parsing_info->orient, \
									cy_parsing_info->height / 2));
	cy_info->disk[1].radius = cy_info->tube.radius;
	cy_info->disk[1].normal = cy_parsing_info->orient;
	cy_info->disk[1].material = cy_info->material;
	cy_info->disk[1].texture = cy_info->texture;
}

int	build_element_cylinder(
	t_world *world,
	t_parsing_info_object_cylinder *cy_parsing_info)
{
	t_info_object_cylinder	cy_info;

	cy_info.material.type = MATERIAL_LAMBERTIAN;
	cy_info.texture.type = TEXTURE_SOLID;
	cy_info.texture.rgb1 = cy_parsing_info->rgb;
	_build_element_cylinder_tube(&cy_info, cy_parsing_info);
	_build_element_cylinder_disks(&cy_info, cy_parsing_info);
	if (add_object_to_world(world, new_cylinder(&cy_info)) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
