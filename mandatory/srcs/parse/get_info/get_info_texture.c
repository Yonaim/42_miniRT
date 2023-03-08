#include "../parse_internal.h"

t_info_texture	get_info_texture(const t_token_arr *tokens, int offset)
{
	t_info_texture	tex_info;

	tex_info.type = get_texture_type(nth_token(tokens, offset)->str);
	offset++;
	if (tex_info.type == TEXTURE_SOLID)
		tex_info.rgb1 = parse_vector3(tokens, &offset);
	else if (tex_info.type == TEXTURE_CHECKER)
	{
		tex_info.rgb1 = parse_vector3(tokens, &offset);
		tex_info.rgb2 = parse_vector3(tokens, &offset);
	}
	else if (tex_info.type == TEXTURE_IMAGE)
		tex_info.path = ft_strdup(nth_token(tokens, offset)->str);
	return (tex_info);
}
