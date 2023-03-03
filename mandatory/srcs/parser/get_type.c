
#include "parser.h"

static int	get_idx_matching_string(char **strs, char *search)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		if (strcmp(search, strs[i]) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int	get_element_type(t_token *token)
{
	const char	*identifier[] = {
	[ELEMENT_CAMERA] = IDETIFIER_ELEMENT_CAMERA,
	[ELEMENT_AMBIENT] = IDETIFIER_ELEMENT_AMBIENT,
	[ELEMENT_LIGHT] = IDETIFIER_ELEMENT_LIGHT,
	[ELEMENT_SPHERE] = IDETIFIER_ELEMENT_SPHERE,
	[ELEMENT_PLANE] = IDETIFIER_ELEMENT_PLANE,
	[ELEMENT_CYLINDER] = IDETIFIER_ELEMENT_CYLINDER,
	[ELEMENT_CONE] = IDETIFIER_ELEMENT_CONE,
	[ELEMENT_BOX] = IDETIFIER_ELEMENT_BOX,
		NULL
	};
	int			type;

	if (token->type != TOKEN_WORD)
		return (ELEMENT_NONE);
	type = get_idx_matching_string(identifier, token->str);
	if (type == -1)
		return (ELEMENT_NONE);
	return (type);
}

int	get_material_type(t_token *token)
{
	const char	*identifier[] = {
	[MATERIAL_LAMBERTIAL] = IDETIFIER_MATERIAL_LAMBERTIAL,
	[MATERIAL_METAL] = IDETIFIER_MATERIAL_METAL,
	[MATERIAL_DIELECTRIC] = IDETIFIER_MATERIAL_DIELECTRIC,
	[MATERIAL_EMMISIVE] = IDETIFIER_MATERIAL_EMMISIVE,
	[MATERIAL_RANDOM] = IDETIFIER_MATERIAL_RANDOM,
		NULL
	};
	int			type;

	if (token->type != TOKEN_WORD)
		return (ELEMENT_NONE);
	type = get_idx_matching_string(identifier, token->str);
	if (type == -1)
		return (ELEMENT_NONE);
	return (type);
}

int	get_texture_type(t_token *token)
{
	const char	*identifier[] = {
	[TEXTURE_SOLID] = IDETIFIER_TEXTURE_SOLID,
	[TEXTURE_CHECKER] = IDETIFIER_TEXTURE_CHECKER,
	[TEXTURE_IMAGE] = IDETIFIER_TEXTURE_IMAGE,
		NULL
	};
	int			type;

	if (token->type != TOKEN_WORD)
		return (ELEMENT_NONE);
	type = get_idx_matching_string(identifier, token->str);
	if (type == -1)
		return (ELEMENT_NONE);
	return (type);
}