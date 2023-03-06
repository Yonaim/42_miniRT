#include "../parse_internal.h"

/*
	(example)

	Solid element의 경우 '<elem_id> | <고유 정보> [material 및 texture]'와 같은 형식으로 들어온다.
		- material 및 texture가 없는 경우
			ex) sp | (0, 0, 20) 20 | (255, 0, 0)
		- material 및 texture가 있는 경우
			ex) sp | (0, 0, 20) 20 | lam sol (255, 0, 0)

	pl | (0,0,0) (0,1.0,0) | (255,0,225) 
	sp | (0,0,20) 20 | (255,0,0)
	cy | (50.0,0.0,20.6) (0.0,0.0,1.0) 14.2 21.42 | (10,0,255)
	co | (50.0,0.0,20.6) (0.0,0.0,1.0) 14.2 21.42 | (10,0,255)
	bo | (30,0,0) (0,20,10) | (255,255,255)
	(p_end1, p_end2, rgb)
*/
t_info_material get_info_material(const t_token_arr *tokens, int offset)
{
	t_info_material	m_info;

	offset++;
	if (nth_token(tokens, offset)->type == TOKEN_IDENTIFIER_MATERIAL)
	{
		m_info.type = get_material_type(nth_token(tokens, offset)->str);
		m_info.texture.type = get_texture_type(\
											nth_token(tokens, offset + 1)->str);
		offset += 2;
	}
	else
	{
		m_info.type = DEFAULT_MATERIAL;
		m_info.texture.type = DEFAULT_TEXTURE;
	}	
	m_info.texture.rgb1 = parse_vector3(tokens, &offset);
	return (m_info);
}

t_info		*get_info_point_light(const t_token_arr *tokens)
{
	t_info_object_point_light	*info;
	int							offset;
	
	info = malloc(sizeof(t_info_object_point_light));
	if (info == NULL)
		return (NULL);
	offset = 2;
	info->pos = parse_vector3(tokens, &offset);
	info->brightness = parse_number(tokens, &offset);
	info->rgb = parse_vector3(tokens, &offset);
	if (is_num_in_range(info->brightness, 0, 1) == false \
		|| is_color3_in_255(&info->rgb) == false)
	{
		free(info);
		return (NULL);
	}
	return ((t_info *)info);
}

t_info		*get_info_plane(const t_token_arr *tokens)
{
	t_info_object_plane	*info;
	int					offset;
	
	info = malloc(sizeof(t_info_object_plane));
	if (info == NULL)
		return (NULL);
	offset = 2;
	info->point = parse_vector3(tokens, &offset);
	info->normal = parse_vector3(tokens, &offset);
	info->material = get_info_material(tokens, offset);
	if (is_normalized_vec3(&info->normal) == false \
		|| is_color3_in_255(&info->material.texture.rgb1) == false)
	{
		free(info);
		return (NULL);
	}
	return ((t_info *)info);
}

t_info		*get_info_sphere(const t_token_arr *tokens)
{
	t_info_object_sphere	*info;
	int						offset;
	
	info = malloc(sizeof(t_info_object_sphere));
	if (info == NULL)
		return (NULL);
	offset = 2;
	info->center = parse_vector3(tokens, &offset);
	info->radius = parse_number(tokens, &offset) / 2;
	info->material = get_info_material(tokens, offset);
	if (is_color3_in_255(&info->material.texture.rgb1) == false)
	{
		free(info);
		return (NULL);
	}
	return ((t_info *)info);
}

t_info		*get_info_disk(const t_token_arr *tokens)
{
	t_info_object_disk	*info;
	int					offset;
	
	info = malloc(sizeof(t_info_object_disk));
	if (info == NULL)
		return (NULL);
	offset = 2;
	info->center = parse_vector3(tokens, &offset);
	info->normal = parse_vector3(tokens, &offset);
	info->radius = parse_number(tokens, &offset) / 2;
	while (nth_token(tokens, offset)->type == TOKEN_NUMBER)
		offset++;
	info->material = get_info_material(tokens, offset);
	if (is_normalized_vec3(&info->normal) == false \
		|| is_color3_in_255(&info->material.texture.rgb1) == false)
	{
		free(info);
		return (NULL);
	}
	return ((t_info *)info);
}

t_info		*get_info_tube(const t_token_arr *tokens)
{
	t_info_object_tube	*info;
	int					offset;
	
	info = malloc(sizeof(t_info_object_tube));
	if (info == NULL)
		return (NULL);
	offset = 2;
	info->center = parse_vector3(tokens, &offset);
	info->orient = parse_vector3(tokens, &offset);
	info->radius = parse_number(tokens, &offset) / 2;
	info->height = parse_number(tokens, &offset);
	info->material = get_info_material(tokens, offset);
	if (is_normalized_vec3(&info->orient) == false \
		|| is_color3_in_255(&info->material.texture.rgb1) == false)
	{
		free(info);
		return (NULL);
	}
	return ((t_info *)info);
}

t_info		*get_info_cylinder(const t_token_arr *tokens)
{
	t_info_object_cylinder	*cy_info;
	t_info_object_disk		*di_info;
	t_info_object_tube		*tu_info;
	
	cy_info = malloc(sizeof(t_info_object_cylinder));
	di_info = (t_info_object_disk *)get_info_disk(tokens);
	tu_info = (t_info_object_tube *)get_info_tube(tokens);
	if (cy_info == NULL || di_info == NULL || tu_info == NULL)
		return (NULL);
	ft_memcpy(&cy_info->disk[0], di_info, sizeof(t_info_object_disk));
	ft_memcpy(&cy_info->disk[1], di_info, sizeof(t_info_object_disk));
	ft_memcpy(&cy_info->tube, tu_info, sizeof(t_info_object_tube));
	cy_info->disk[0].center = v3_sub(tu_info->center, \
								v3_mul(tu_info->orient, tu_info->height / 2));
	cy_info->disk[1].center = v3_add(tu_info->center, \
								v3_mul(tu_info->orient, tu_info->height / 2));
	free(di_info);
	free(tu_info);
	return ((t_info *)cy_info);
}

t_info		*get_info_cone_lateral(const t_token_arr *tokens)
{
	t_info_object_cone_lateral	*info;
	int							offset;
	
	info = malloc(sizeof(t_info_object_cone_lateral));
	if (info == NULL)
		return (NULL);
	offset = 2;
	info->center = parse_vector3(tokens, &offset);
	info->orient = parse_vector3(tokens, &offset);
	info->radius = parse_number(tokens, &offset) / 2;
	info->height = parse_number(tokens, &offset);
	info->material = get_info_material(tokens, offset);
	if (is_normalized_vec3(&info->orient) == false \
		|| is_color3_in_255(&info->material.texture.rgb1) == false)
	{
		free(info);
		return (NULL);
	}
	return ((t_info *)info);
}

t_info		*get_info_cone(const t_token_arr *tokens)
{
	t_info_object_cone			*co_info;
	t_info_object_disk			*di_info;
	t_info_object_cone_lateral	*cl_info;
	
	co_info = malloc(sizeof(t_info_object_cone));
	di_info = (t_info_object_disk *)get_info_disk(tokens);
	cl_info = (t_info_object_cone_lateral *)get_info_cone_lateral(tokens);
	if (co_info == NULL || di_info == NULL || cl_info == NULL)
		return (NULL);
	ft_memcpy(&co_info->disk, di_info, sizeof(t_info_object_disk));
	ft_memcpy(&co_info->lateral, cl_info, sizeof(t_info_object_cone_lateral));
	free(di_info);
	free(cl_info);
	return ((t_info *)co_info);
}

t_info		*get_info_box(const t_token_arr *tokens)
{
	t_info_object_box	*info;
	int					offset;
	
	info = malloc(sizeof(t_info_object_box));
	if (info == NULL)
		return (NULL);
	offset = 2;
	info->p_end1 = parse_vector3(tokens, &offset);
	info->p_end2 = parse_vector3(tokens, &offset);
	info->material = get_info_material(tokens, offset);
	if (is_color3_in_255(&info->material.texture.rgb1) == false)
	{
		free(info);
		return (NULL);
	}
	return ((t_info *)info);
}
