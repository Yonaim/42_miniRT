#include "texture_internal.h"
#include "s_info_element.h"

t_texture	*new_texture(t_info_texture *texture_info)
{
	if (texture_info == NULL)
		return (NULL);
	if (texture_info->type == TEXTURE_SOLID)
		return (new_solid(texture_info->rgb1));
	else if (texture_info->type == TEXTURE_CHECKER)
		return (new_checker_solid(texture_info->rgb1, texture_info->rgb2));
	else if (texture_info->type == TEXTURE_IMAGE)
		return (NULL);
	return (NULL);
}
