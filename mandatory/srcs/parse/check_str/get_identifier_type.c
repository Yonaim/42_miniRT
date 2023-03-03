
#include "parse_internal.h"
#include <string.h>

static int	get_idx_matching_string(const char **strs, const char *seek)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		if (strcmp(seek, strs[i]) == 0) // TODO
			return (i);
		i++;
	}
	return (-1);
}

int	get_element_type(const char *str)
{
	const char	*identifier[] = {
	[ELEMENT_CAMERA] = IDENTIFIER_ELEMENT_CAMERA,
	[ELEMENT_AMBIENT] = IDENTIFIER_ELEMENT_AMBIENT,
	[ELEMENT_LIGHT] = IDENTIFIER_ELEMENT_LIGHT,
	[ELEMENT_SPHERE] = IDENTIFIER_ELEMENT_SPHERE,
	[ELEMENT_PLANE] = IDENTIFIER_ELEMENT_PLANE,
	[ELEMENT_CYLINDER] = IDENTIFIER_ELEMENT_CYLINDER,
	[ELEMENT_CONE] = IDENTIFIER_ELEMENT_CONE,
	[ELEMENT_BOX] = IDENTIFIER_ELEMENT_BOX,
		NULL
	};

	return (get_idx_matching_string(identifier, str));
}

int	get_material_type(const char *str)
{
	const char	*identifier[] = {
	[MATERIAL_LAMBERTIAL] = IDENTIFIER_MATERIAL_LAMBERTIAL,
	[MATERIAL_METAL] = IDENTIFIER_MATERIAL_METAL,
	[MATERIAL_DIELECTRIC] = IDENTIFIER_MATERIAL_DIELECTRIC,
	[MATERIAL_EMMISIVE] = IDENTIFIER_MATERIAL_EMMISIVE,
	[MATERIAL_RANDOM] = IDENTIFIER_MATERIAL_RANDOM,
		NULL
	};
	
	return (get_idx_matching_string(identifier, str));
}

int	get_texture_type(const char *str)
{
	const char	*identifier[] = {
	[TEXTURE_SOLID] = IDENTIFIER_TEXTURE_SOLID,
	[TEXTURE_CHECKER] = IDENTIFIER_TEXTURE_CHECKER,
	[TEXTURE_IMAGE] = IDENTIFIER_TEXTURE_IMAGE,
		NULL
	};

	return (get_idx_matching_string(identifier, str));
}