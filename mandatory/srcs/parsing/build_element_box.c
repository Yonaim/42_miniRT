#include "parsing_internel.h"

void	_build_element_box_xy_rectangle(
		t_info_object_box	*bo_info,
		t_point3 *p_end1, t_point3 *p_end2)
{
	bo_info->xy_rectangle[0].material = bo_info->material;
	bo_info->xy_rectangle[0].texture = bo_info->texture;
	bo_info->xy_rectangle[0].x1 = p_end1->x;
	bo_info->xy_rectangle[0].x2 = p_end2->x;
	bo_info->xy_rectangle[0].y1 = p_end1->y;
	bo_info->xy_rectangle[0].y2 = p_end2->y;
	bo_info->xy_rectangle[0].z = p_end1->z;
	bo_info->xy_rectangle[1].material = bo_info->material;
	bo_info->xy_rectangle[1].texture = bo_info->texture;
	bo_info->xy_rectangle[1].x1 = p_end1->x;
	bo_info->xy_rectangle[1].x2 = p_end2->x;
	bo_info->xy_rectangle[1].y1 = p_end1->y;
	bo_info->xy_rectangle[1].y2 = p_end2->y;
	bo_info->xy_rectangle[1].z = p_end2->z;
}

void	_build_element_box_xz_rectangle(
		t_info_object_box	*bo_info,
		t_point3 *p_end1, t_point3 *p_end2)
{
	bo_info->xz_rectangle[0].material = bo_info->material;
	bo_info->xz_rectangle[0].texture = bo_info->texture;
	bo_info->xz_rectangle[0].x1 = p_end1->x;
	bo_info->xz_rectangle[0].x2 = p_end2->x;
	bo_info->xz_rectangle[0].z1 = p_end1->z;
	bo_info->xz_rectangle[0].z2 = p_end2->z;
	bo_info->xz_rectangle[0].y = p_end1->y;
	bo_info->xz_rectangle[1].material = bo_info->material;
	bo_info->xz_rectangle[1].texture = bo_info->texture;
	bo_info->xz_rectangle[1].x1 = p_end1->x;
	bo_info->xz_rectangle[1].x2 = p_end2->x;
	bo_info->xz_rectangle[1].z1 = p_end1->z;
	bo_info->xz_rectangle[1].z2 = p_end2->z;
	bo_info->xz_rectangle[1].y = p_end2->y;
}

void	_build_element_box_yz_rectangle(
		t_info_object_box	*bo_info,
		t_point3 *p_end1, t_point3 *p_end2)
{
	bo_info->yz_rectangle[0].material = bo_info->material;
	bo_info->yz_rectangle[0].texture = bo_info->texture;
	bo_info->yz_rectangle[0].y1 = p_end1->y;
	bo_info->yz_rectangle[0].y2 = p_end2->y;
	bo_info->yz_rectangle[0].z1 = p_end1->z;
	bo_info->yz_rectangle[0].z2 = p_end2->z;
	bo_info->yz_rectangle[0].x = p_end1->x;
	bo_info->yz_rectangle[1].material = bo_info->material;
	bo_info->yz_rectangle[1].texture = bo_info->texture;
	bo_info->yz_rectangle[1].y1 = p_end1->y;
	bo_info->yz_rectangle[1].y2 = p_end2->y;
	bo_info->yz_rectangle[1].y1 = p_end1->y;
	bo_info->yz_rectangle[1].y2 = p_end2->y;
	bo_info->yz_rectangle[1].x = p_end2->x;
}

int	build_element_box(
	t_object_arr *objects,
	t_point3 *p_end1, t_point3 *p_end2, t_vector3 *rgb)
{
	t_info_object_box	bo_info;

	bo_info.material.type = MATERIAL_LAMBERTIAN;
	bo_info.texture.type = TEXTURE_SOLID;
	bo_info.texture.rgb1 = *rgb;
	_build_element_box_xy_rectangle(&bo_info, p_end1, p_end2);
	_build_element_box_xz_rectangle(&bo_info, p_end1, p_end2);
	_build_element_box_yz_rectangle(&bo_info, p_end1, p_end2);
	if (add_object(objects, new_box(&bo_info)) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
