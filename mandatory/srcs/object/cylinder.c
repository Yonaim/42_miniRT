#include "object_internal.h"

static void	destroy_cylinder(t_object *object);
static int	get_cylinder_type(void);
static bool	hit_cylinder(t_object *self, t_ray *ray, \
						t_hit_record *h_rec, double t_max);

// DISCUSS 1: 메모리 할당 실패 시 내부에서 할당 성공한 것을 free하고 NULL을 반환할지 
//          아니면 어차피 외부에서 handle_error 함수를 호출하면 바로 종료되니까
//          그냥 NULL을 반환할지 결정

t_object	*new_cylinder(t_info_object_cylinder *cy_info)
{
	t_object_cylinder	*new;

	new = malloc(sizeof(t_object_cylinder));
	if (!new)
		return (NULL);
	new->hit = hit_cylinder;
	new->destroy = destroy_cylinder;
	new->get_type = get_cylinder_type;
	if (init_object_arr(&new->faces, 3) == FAILURE)
		return (NULL);
	if (add_object(&new->faces, new_tube(&cy_info->tube)) == FAILURE
		|| add_object(&new->faces, new_disk(&cy_info->disk[0])) == FAILURE
		|| add_object(&new->faces, new_disk(&cy_info->disk[1])) == FAILURE)
		return (NULL);
	return ((t_object *)new);
}

static void	destroy_cylinder(t_object *object)
{
	t_object_cylinder	*cy;

	cy = (t_object_cylinder *)object;
	cy->material->destroy(cy->material);
	clear_object_arr(&cy->faces);
	free(cy);
}

static int	get_cylinder_type(void)
{
	return (OBJECT_CYLINDER);
}

/*
	<Line-Cylinder intersection>

	The cylinder consists of three faces, one tube and two disks.
	Check the intersection of these faces and line.
*/
static bool	hit_cylinder(t_object *self, t_ray *ray, \
						t_hit_record *h_rec, double t_max)
{
	t_object_cylinder	*cy;

	cy = (t_object_cylinder *)self;
	return (hit_object_arr(&cy->faces, ray, h_rec, t_max));
}
