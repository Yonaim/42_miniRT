#include "parsing_internel.h"

int	build_element_point_light(
	t_object_arr *objects, t_point3 *pos, double *brightness, t_vector3 *rgb)
{
	t_info_object_point_light	ptl_info;

	ptl_info.pos = *pos;
	ptl_info.brightness = *brightness;
	ptl_info.rgb = *rgb;
	if (add_object(objects, new_point_light(&ptl_info)) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	build_element_plane(
	t_object_arr *objects, t_point3 *pos, t_vector3 *normal, t_vector3 *rgb)
{
	t_info_object_plane	pl_info;

	pl_info.point = *pos;
	pl_info.normal = v3_normalize(*normal);
	pl_info.material.type = MATERIAL_LAMBERTIAN;
	pl_info.texture.type = TEXTURE_SOLID;
	pl_info.texture.rgb1 = *rgb;
	if (add_object(objects, new_plane(&pl_info)) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	build_element_sphere(
	t_object_arr *objects, t_point3 *pos, double *diameter, t_vector3 *rgb)
{
	t_info_object_sphere	sp_info;

	sp_info.center = *pos;
	sp_info.radius = *diameter / 2;
	sp_info.material.type = MATERIAL_LAMBERTIAN;
	sp_info.texture.type = TEXTURE_SOLID;
	sp_info.texture.rgb1 = *rgb;
	if (add_object(objects, new_sphere(&sp_info)) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
