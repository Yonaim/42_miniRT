#include "object_internal.h"

static void	_set_xy_rectangle_info(
	t_info_object_xy_rectangle *xy_rec_info, const t_info_object_box *bo_info)
{
	xy_rec_info[0].material = bo_info->material;
	xy_rec_info[0].x1 = bo_info->p_end1.x;
	xy_rec_info[0].x2 = bo_info->p_end2.x;
	xy_rec_info[0].y1 = bo_info->p_end1.y;
	xy_rec_info[0].y2 = bo_info->p_end2.y;
	xy_rec_info[0].z = bo_info->p_end1.z;
	xy_rec_info[1].material = bo_info->material;
	xy_rec_info[1].x1 = bo_info->p_end1.x;
	xy_rec_info[1].x2 = bo_info->p_end2.x;
	xy_rec_info[1].y1 = bo_info->p_end1.y;
	xy_rec_info[1].y2 = bo_info->p_end2.y;
	xy_rec_info[1].z = bo_info->p_end2.z;
}

static void	_set_xz_rectangle_info(
	t_info_object_xz_rectangle *xz_rec_info, const t_info_object_box *bo_info)
{
	xz_rec_info[0].material = bo_info->material;
	xz_rec_info[0].x1 = bo_info->p_end1.x;
	xz_rec_info[0].x2 = bo_info->p_end2.x;
	xz_rec_info[0].z1 = bo_info->p_end1.z;
	xz_rec_info[0].z2 = bo_info->p_end2.z;
	xz_rec_info[0].y = bo_info->p_end1.y;
	xz_rec_info[1].material = bo_info->material;
	xz_rec_info[1].x1 = bo_info->p_end1.x;
	xz_rec_info[1].x2 = bo_info->p_end2.x;
	xz_rec_info[1].z1 = bo_info->p_end1.z;
	xz_rec_info[1].z2 = bo_info->p_end2.z;
	xz_rec_info[1].y = bo_info->p_end2.y;
}

static void	_set_yz_rectangle_info(
	t_info_object_yz_rectangle *yz_rec_info, const t_info_object_box *bo_info)
{
	yz_rec_info[0].material = bo_info->material;
	yz_rec_info[0].y1 = bo_info->p_end1.y;
	yz_rec_info[0].y2 = bo_info->p_end2.y;
	yz_rec_info[0].z1 = bo_info->p_end1.z;
	yz_rec_info[0].z2 = bo_info->p_end2.z;
	yz_rec_info[0].x = bo_info->p_end1.x;
	yz_rec_info[1].material = bo_info->material;
	yz_rec_info[1].y1 = bo_info->p_end1.y;
	yz_rec_info[1].y2 = bo_info->p_end2.y;
	yz_rec_info[1].z1 = bo_info->p_end1.z;
	yz_rec_info[1].z2 = bo_info->p_end2.z;
	yz_rec_info[1].x = bo_info->p_end2.x;
}


int	add_box_faces(t_object_box *box, const t_info_object_box *bo_info)
{
	t_info_object_xy_rectangle	xy_rec_info[2];
	t_info_object_xz_rectangle	xz_rec_info[2];
	t_info_object_yz_rectangle	yz_rec_info[2];
	t_object					*objects[6];

	_set_xy_rectangle_info(xy_rec_info, bo_info);
	_set_xz_rectangle_info(xz_rec_info, bo_info);
	_set_yz_rectangle_info(yz_rec_info, bo_info);
	objects[0] = new_xy_rectangle(&xy_rec_info[0]);
	objects[1] = new_xy_rectangle(&xy_rec_info[1]);
	objects[2] = new_xz_rectangle(&xz_rec_info[0]);
	objects[3] = new_xz_rectangle(&xz_rec_info[1]);
	objects[4] = new_yz_rectangle(&yz_rec_info[0]);
	objects[5] = new_yz_rectangle(&yz_rec_info[1]);
	if (add_n_objects(&box->faces, objects, 6) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
